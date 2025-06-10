// This example code is in the Public Domain (or CC0 licensed, at your option.)
// By Evandro Copercini - 2018
//
// This example creates a bridge between Serial and Classical Bluetooth (SPP)
// and also demonstrate that SerialBT have the same functionalities of a normal Serial
// Note: Pairing is authenticated automatically by this device

#include "BluetoothSerial.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        5
#define NUMPIXELS 300

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

String device_name = "GenderBlender";

#define DELAYVAL 20

// Trans flag colors (approximate)
uint32_t TRANS_BLUE = pixels.Color(1, 97, 138);
uint32_t TRANS_PINK = pixels.Color(163, 44, 68);
uint32_t TRANS_WHITE = pixels.Color(255, 255, 255);

enum LEDPattern {
    RAINBOW = 0,
    TRANS_FLAG_STATIC = 1,
    MIXED_RAINBOW_TRANS_FLAG = 2,
    // Add more patterns as needed
};

LEDPattern currentPattern = RAINBOW;

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

void setup() {
  //Serial.begin(115200);
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  //Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  pixels.begin();
}

void loop() {
    checkForNewBluetoothCommands();
    switchBetweenLEDControlPatterns();
  
  delay(DELAYVAL);
}

void checkForNewBluetoothCommands() {
  if (SerialBT.available()) {
      String incomingString = SerialBT.readString();
      incomingString.trim(); 
      int ledIndex = incomingString.toInt();
      currentPattern = static_cast<LEDPattern>(ledIndex);
  }
}

void switchBetweenLEDControlPatterns() {
    if (currentPattern == RAINBOW) {
        fullRainbowPattern();
    }
    else if (currentPattern == TRANS_FLAG_STATIC) {
        staticTransFlagPattern();
    }
    else if (currentPattern == MIXED_RAINBOW_TRANS_FLAG) {
        mixedRainbowTransFlagPattern();
    }   
}

void fullRainbowPattern() {
    static uint8_t rainbowHue = 0;
    rainbowHue++; // Animate the rainbow
    if (rainbowHue == NUMPIXELS) {
      rainbowHue = 0;
    }

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i,pixels.ColorHSV((rainbowHue + i )  * ( 65536/NUMPIXELS) ));
    }

    pixels.show();
    delay(DELAYVAL);
}

void staticTransFlagPattern() {
    drawTransFlag(0, NUMPIXELS);
    pixels.show();
    delay(DELAYVAL);
}

void drawTransFlag(int startPos, int endPos) {
    int length = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        int pos = i - startPos;
        if (pos < length / 5) {
            pixels.setPixelColor(i, TRANS_BLUE);
        } else if (pos < (length / 5) * 2) {
            pixels.setPixelColor(i, TRANS_PINK);
        } else if (pos < (length / 5) * 3) {
            pixels.setPixelColor(i, TRANS_WHITE);
        } else if (pos < (length / 5) * 4) {
            pixels.setPixelColor(i, TRANS_PINK);
        } else {
            pixels.setPixelColor(i, TRANS_BLUE);
        }
    }
}

void mixedRainbowTransFlagPattern() {
    static uint8_t rainbowHue = 0;
    rainbowHue++; // Animate the rainbow

    int sectionLength = NUMPIXELS / 3; 

    if (rainbowHue == sectionLength) {
      rainbowHue = 0;
    }
    

    // Rainbow on 0-99
    for (int i = 0; i < sectionLength; i++) {
      pixels.setPixelColor(i,pixels.ColorHSV((rainbowHue + i )  * ( 65536/sectionLength) ));
    }

    // Trans flag on 100-199
    drawTransFlag(sectionLength, sectionLength * 2);

    // Rainbow on 200-299
    for (int i = sectionLength * 2; i < sectionLength * 3; i++) {
      pixels.setPixelColor(i,pixels.ColorHSV((rainbowHue + (i-(2* sectionLength)) )  * ( 65536/sectionLength) ));
    }

    pixels.show();
    delay(DELAYVAL);
}
