/***************************************************************************** 
 * GenderBlender - Bluetooth Swapped Light Patterns  *
 *****************************************************************************/
#include "BluetoothSerial.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        5
#define NUMPIXELS 738

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

String device_name = "GenderBlender";

#define DELAYVAL 20

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

/***************************************************************************** 
 * Setup, loop and utility functions *
 *****************************************************************************/

void setup() {
  setupBluetooth();
  pixels.begin();
  initializeButton();
}

void loop() {
    checkForNewBluetoothCommands();
    checkButtonState();
    if (!isInDebugMode()) {
      switchBetweenLEDControlPatterns();
    }
}





 