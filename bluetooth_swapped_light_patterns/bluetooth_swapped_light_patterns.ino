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
    SEPARATE_LETTER_COLORS = 3,
    // Add more patterns as needed
};

const int LETTER_COUNT = 13;

// Start and end pixel indices for each letter in "GENDERBLENDER"
// Example: {start, end} for each letter (inclusive start, exclusive end)
const int LETTER_PIXEL_RANGES[LETTER_COUNT][2] = {
    {0, 20},    // G
    {22, 42},   // E
    {44, 64},   // N
    {66, 86},   // D
    {88, 108},  // E
    {110, 130}, // R
    {132, 152}, // B
    {154, 174}, // L
    {176, 196}, // E
    {198, 218}, // N
    {220, 240}, // D
    {242, 264}, // E
    {266, 300}  // R
};

// Optional: Character labels for reference
const char* LETTER_LABELS[LETTER_COUNT] = {
    "G", "E", "N", "D", "E", "R", "B", "L", "E", "N", "D", "E", "R"
};

// Example colors for each letter (customize as needed)
const uint32_t LETTER_COLORS[LETTER_COUNT] = {
    pixels.Color(255, 0, 0),    // Red
    pixels.Color(255, 128, 0),  // Orange
    pixels.Color(255, 255, 0),  // Yellow
    pixels.Color(0, 255, 0),    // Green
    pixels.Color(0, 255, 255),  // Cyan
    pixels.Color(0, 0, 255),    // Blue
    pixels.Color(128, 0, 255),  // Purple
    pixels.Color(255, 0, 255),  // Magenta
    pixels.Color(255, 0, 128),  // Pink
    pixels.Color(128, 128, 128),// Gray
    pixels.Color(255, 255, 255),// White
    pixels.Color(128, 64, 0),   // Brown
    pixels.Color(50, 50, 50)       // Grey
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
    else if (currentPattern == SEPARATE_LETTER_COLORS) {
        setEachLetterToDifferentColor();
    }
}

void fullRainbowPattern() {
    static uint16_t rainbowHue = 0;
    rainbowHue++; // Animate the rainbow
    if (rainbowHue == NUMPIXELS) {
      rainbowHue = 0;
    }
    drawRainbowSection(0, NUMPIXELS, rainbowHue); 
    pixels.show();
    delay(DELAYVAL/3);
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

void drawRainbowSection(int startPos, int endPos, uint16_t rainbowHue) {
    int sectionLength = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        pixels.setPixelColor(i, pixels.ColorHSV((int)((rainbowHue + i - sectionLength/2) * (65536.0 / sectionLength))));
    }
}

void mixedRainbowTransFlagPattern() {
    static uint16_t rainbowHue = 0;
    rainbowHue++; // Animate the rainbow

    int sectionLength = NUMPIXELS / 3; 

    if (rainbowHue == sectionLength) {
      rainbowHue = 0;
    }
    
    // Rainbow on 0-99
    drawRainbowSection(0, sectionLength, rainbowHue); 

    // Trans flag on 100-199
    drawTransFlag(sectionLength, sectionLength * 2);

    // Rainbow on 200-299
    drawRainbowSection(sectionLength * 2, sectionLength * 3, rainbowHue);

    pixels.show();
    delay(DELAYVAL);
}

// Sample function to set each letter to a different color
void setEachLetterToDifferentColor() {
    // Clear all pixels first
    for (int i = 0; i < NUMPIXELS; ++i) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Set all pixels to black
    }
    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        uint32_t color = LETTER_COLORS[i];
        for (int j = start; j < end; ++j) {
            pixels.setPixelColor(j, color);
        }
    }
    pixels.show();
}
