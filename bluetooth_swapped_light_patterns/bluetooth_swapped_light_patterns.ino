/***************************************************************************** 
 * GenderBlender - Bluetooth Swapped Light Patterns  *
 *****************************************************************************/
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


/***************************************************************************** 
 * HSV Color Definitions for Pride Flags * 
 *****************************************************************************/

//Trans Flag
//Blue = 180 to 250
//Pink = 280 to 320
uint16_t TRANS_BLUE_HUE_BASE = (65536 * 215 ) / 360;
uint16_t TRANS_PINK_HUE_BASE = (65536 * 300 ) / 360;   
uint16_t TRANS_BLUE_HUE_RANGE = (uint16_t)((65536 * 70)/360); 
uint16_t TRANS_PINK_HUE_RANGE = (uint16_t)((65536 * 40)/360);


// Nonbinary Flag
//Yellow = 50 to 65
//Purple = 265 to 285
uint16_t NONBINARY_YELLOW_HUE_BASE = (65536 * 57 ) / 360;
uint16_t NONBINARY_PURPLE_HUE_BASE = (65536 * 275 ) / 360;
uint16_t NONBINARY_YELLOW_HUE_RANGE = (uint16_t)((65536 * 15)/360);
uint16_t NONBINARY_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

// Pansexual Flag
//Pink = 290 to 330
//Yellow = 50 to 65
//Blue = 200 to 220
uint16_t PAN_PINK_HUE_BASE = (65536 * 310 ) / 360;
uint16_t PAN_YELLOW_HUE_BASE = (65536 * 57 ) / 360;
uint16_t PAN_BLUE_HUE_BASE = (65536 * 210 ) / 360;
uint16_t PAN_PINK_HUE_RANGE = (uint16_t)((65536 * 20)/360);
uint16_t PAN_YELLOW_HUE_RANGE = (uint16_t)((65536 * 15)/360);
uint16_t PAN_BLUE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

// Bisexual Flag
//Pink = 290 to 330
//Blue = 200 to 220
//Purple = 265 to 285
uint16_t BISEXUAL_PINK_HUE_BASE = (65536 * 310 ) / 360;
uint16_t BISEXUAL_BLUE_HUE_BASE = (65536 * 210 ) / 360;
uint16_t BISEXUAL_PURPLE_HUE_BASE = (65536 * 275 ) / 360;
uint16_t BISEXUAL_PINK_HUE_RANGE = (uint16_t)((65536 * 40)/360);
uint16_t BISEXUAL_BLUE_HUE_RANGE = (uint16_t)((65536 * 20)/360);
uint16_t BISEXUAL_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

// Lesbian Flag
//Red = 10 to 20
//Dark Orange = 20 to 30
//Light Orange = 30 to 40
//Magenta = 270 to 290
//Dark Pink = 290 to 310
//Pink = 310 to 330
uint16_t LESBIAN_RED_HUE_BASE = (65536 * 15 ) / 360;
uint16_t LESBIAN_DARK_ORANGE_HUE_BASE = (65536 * 25 ) / 360;
uint16_t LESBIAN_LIGHT_ORANGE_HUE_BASE = (65536 * 35 ) / 360;
uint16_t LESBIAN_MAGENTA_HUE_BASE = (65536 * 280 ) / 360;
uint16_t LESBIAN_DARK_PINK_HUE_BASE = (65536 * 300 ) / 360;
uint16_t LESBIAN_PINK_HUE_BASE = (65536 * 320 ) / 360;
uint16_t LESBIAN_RED_HUE_RANGE = (uint16_t)((65536 * 10)/360);
uint16_t LESBIAN_DARK_ORANGE_HUE_RANGE = (uint16_t)((65536 * 10)/360);
uint16_t LESBIAN_LIGHT_ORANGE_HUE_RANGE = (uint16_t)((65536 * 10)/360);
uint16_t LESBIAN_MAGENTA_HUE_RANGE = (uint16_t)((65536 * 10)/360);
uint16_t LESBIAN_DARK_PINK_HUE_RANGE = (uint16_t)((65536 * 10)/360);
uint16_t LESBIAN_PINK_HUE_RANGE = (uint16_t)((65536 * 20)/360);

// Genderqueer Flag
//Green = 90 to 150
//Purple = 260 to 280
uint16_t GENDERQUEER_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t GENDERQUEER_PURPLE_HUE_BASE = (65536 * 270 ) / 360;
uint16_t GENDERQUEER_GREEN_HUE_RANGE = (uint16_t)((65536 * 60)/360);
uint16_t GENDERQUEER_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

//Genderfluid Flag
//Pink = 300 to 330
//Blue = 200 to 260
//Purple = 260 to 280
uint16_t GENDERFLUID_PINK_HUE_BASE = (65536 * 320 ) / 360;
uint16_t GENDERFLUID_BLUE_HUE_BASE = (65536 * 230 ) / 360;
uint16_t GENDERFLUID_PURPLE_HUE_BASE = (65536 * 270 ) / 360;
uint16_t GENDERFLUID_PINK_HUE_RANGE = (uint16_t)((65536 * 30)/360);
uint16_t GENDERFLUID_BLUE_HUE_RANGE = (uint16_t)((65536 * 60)/360);
uint16_t GENDERFLUID_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

//Agender Flag
//Green = 90 to 150
uint16_t AGENDER_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t AGENDER_GREEN_HUE_RANGE = (uint16_t)((65536 * 60)/360);

//Intersex Flag
//Yellow = 50 to 65
//Purple = 265 to 285
uint16_t INTERSEX_YELLOW_HUE_BASE = (65536 * 57 ) / 360;
uint16_t INTERSEX_PURPLE_HUE_BASE = (65536 * 275 ) / 360;
uint16_t INTERSEX_YELLOW_HUE_RANGE = (uint16_t)((65536 * 15)/360);
uint16_t INTERSEX_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

//Polysexual Flag
//Pink = 280 to 330
//Green = 90 to 150
//Blue = 200 to 260
uint16_t POLYSEXUAL_PINK_HUE_BASE = (65536 * 310 ) / 360;
uint16_t POLYSEXUAL_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t POLYSEXUAL_BLUE_HUE_BASE = (65536 * 230 ) / 360;
uint16_t POLYSEXUAL_PINK_HUE_RANGE = (uint16_t)((65536 * 50)/360);
uint16_t POLYSEXUAL_GREEN_HUE_RANGE = (uint16_t)((65536 * 60)/360);
uint16_t POLYSEXUAL_BLUE_HUE_RANGE = (uint16_t)((65536 * 60)/360);

//Asexual Flag
//Purple = 260 to 280
uint16_t ASEXUAL_PURPLE_HUE_BASE = (65536 * 270 ) / 360;
uint16_t ASEXUAL_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

//Aromantic Flag
//Green = 90 to 150
uint16_t AROMANTIC_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t AROMANTIC_GREEN_HUE_RANGE = (uint16_t)((65536 * 60)/360);

//Black Pride Flag (Saturation instead of Hue, all in percents of 255)
//Black = 0 to 20
//Dark Brown = 20 to 40
//Medium Brown = 40 to 60
//Hue = 28, Saturation = 100
//Light Brown = 80 to 100
//Hue = 25, Saturation = 50
uint8_t BLACK_PRIDE_BLACK_SATURATION_BASE = 25; 
uint8_t BLACK_PRIDE_DARK_BROWN_SATURATION_BASE = 75;
uint8_t BLACK_PRIDE_MEDIUM_BROWN_SATURATION_BASE = 125;
uint8_t BLACK_PRIDE_LIGHT_BROWN_SATURATION_BASE = 230;
uint8_t BLACK_PRIDE_BLACK_SATURATION_RANGE = 20;
uint8_t BLACK_PRIDE_DARK_BROWN_SATURATION_RANGE = 20;
uint8_t BLACK_PRIDE_MEDIUM_BROWN_SATURATION_RANGE = 20;
uint16_t BLACK_PRIDE_DARK_HUE = (65536 * 28 ) / 360; // Dark Brown
uint16_t BLACK_PRIDE_LIGHT_HUE = (65536 * 25 ) / 360; // Medium Brown
uint16_t BLACK_PRIDE_DARK_SATURATION = 255;
uint16_t BLACK_PRIDE_LIGHT_SATURATION = 127;


//White, Gray and Black Colors (Value instead of Hue, all in percents of 255)
//White = 80 to 100
//Gray = 60 to 80
//Black = 0 to 40
uint8_t WHITE_VALUE_BASE = 230; // White
uint8_t GRAY_VALUE_BASE = 150; // Gray
uint8_t BLACK_VALUE_BASE = 50; // Black
uint8_t WHITE_VALUE_RANGE = 25; // White
uint8_t GRAY_VALUE_RANGE = 20; // Gray
uint8_t BLACK_VALUE_RANGE = 50; // Black

enum LEDPattern {
    RAINBOW = 0,
    TRANS_FLAG_STATIC = 1,
    MIXED_RAINBOW_TRANS_FLAG = 2,
    SEPARATE_LETTER_COLORS = 3,
    RAINBOW_IN_EACH_LETTER = 4,
    STATIC_TRANS_FLAG_IN_EACH_LETTER = 5,
    TRANS_FLAG_ANIMATED = 6,
    ANIMATED_TRANS_FLAG_IN_EACH_LETTER = 7
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

//Trans flag = 5 colors
//Nonbinary flag = 4 colors
//Pan flag = 3 colors
//Rainbow = 7 colors (or more)

//GEN DE RBL EN DER for trans pattern

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
    pixels.Color(50, 50, 50)       // Dark Grey
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

/***************************************************************************** 
 * Setup, loop and utility functions *
 *****************************************************************************/

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
    else if (currentPattern == RAINBOW_IN_EACH_LETTER) {
        rainbowInEachLetter();
    }
    else if (currentPattern == STATIC_TRANS_FLAG_IN_EACH_LETTER) {
        staticTransFlagInEachLetter();
    }
    else if (currentPattern == TRANS_FLAG_ANIMATED) {
        animatedTransFlagPattern();
    }
    else if (currentPattern == ANIMATED_TRANS_FLAG_IN_EACH_LETTER) {
        animatedTransFlagInEachLetter();
    }
    else {
        // Default to rainbow if an unknown pattern is selected
        fullRainbowPattern();
    }
}

/***************************************************************************** 
 * Utility functions for drawing patterns *
 *****************************************************************************/

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

void animateSingleColorHueSaturationValueVariation(int startPos, int endPos, 
    uint16_t baseHue, uint16_t hueRange, 
    uint8_t baseSaturation, uint8_t saturationRange, 
    uint8_t baseValue, uint8_t valueRange, 
    uint16_t animationIndex, uint16_t animationCycleCount) {
    int length = endPos - startPos;
    for (int i = startPos; i < endPos; ++i) {
        int pos = i - startPos;
        float localPhase = 0.0f;
        uint32_t color = 0;

        // Use animationIndex as the animation driver
        // Offset by pixel for wave
        localPhase = (float)(((animationIndex + pos )) * (360.0f/animationCycleCount)) / 90.0f;
        float s = (sin(localPhase * 2.0f * PI) + 1.0f) / 2.0f;

        uint16_t hue = baseHue - hueRange/2 + (uint16_t)(hueRange * s);
        uint8_t saturation = baseSaturation - saturationRange/2 + (uint8_t)(saturationRange * s);
        uint8_t value = baseValue - valueRange/2 + (uint8_t)(valueRange * s);
        color = pixels.ColorHSV(hue, saturation, value);
        pixels.setPixelColor(i, color);
    }
}

void animatedTransFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    int length = endPos - startPos;
    int section = length / 5;

    for(int j = 0; j < 5; ++j) {
        // Animate each section of the trans flag
        int sectionStart = startPos + j * section;
        int sectionEnd = (j == 4) ? endPos : sectionStart + section; // Last section goes to endPos
        if (j == 0 || j == 4) {
            // Blue sections
            animateSingleColorHueSaturationValueVariation(sectionStart, sectionEnd, 
                TRANS_BLUE_HUE_BASE, TRANS_BLUE_HUE_RANGE,
                255, 0, 255, 0,
                 animationIndex, animationCycleCount);
        } else if (j == 1 || j == 3) {
            // Pink sections
            animateSingleColorHueSaturationValueVariation(sectionStart, sectionEnd, 
                TRANS_PINK_HUE_BASE, TRANS_PINK_HUE_RANGE, 
                255, 0, 255, 0,
                animationIndex, animationCycleCount);
        } else {
            // White section (no animation)
            animateSingleColorHueSaturationValueVariation(sectionStart, sectionEnd, 
                0, 0, 0, 0, 
                WHITE_VALUE_BASE, WHITE_VALUE_RANGE,
                animationIndex, animationCycleCount);
        }
    }
}

void drawRainbowSection(int startPos, int endPos, uint16_t animationIndex) {
    int sectionLength = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        pixels.setPixelColor(i, pixels.ColorHSV((int)((animationIndex + i - sectionLength/2) * (65536.0 / sectionLength))));
    }
}

/***************************************************************************** 
 * LED control patterns *
 *****************************************************************************/

void fullRainbowPattern() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    drawRainbowSection(0, NUMPIXELS, animationIndex); 
    pixels.show();
    delay(DELAYVAL/3);
}

void staticTransFlagPattern() {
    drawTransFlag(0, NUMPIXELS);
    pixels.show();
    delay(DELAYVAL);
}

void animatedTransFlagPattern() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    animatedTransFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    pixels.show();
    delay(DELAYVAL);
}

void mixedRainbowTransFlagPattern() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow

    int sectionLength = NUMPIXELS / 3; 
    if (animationIndex == sectionLength) {
      animationIndex = 0;
    }
    // Rainbow on 0-99
    drawRainbowSection(0, sectionLength, animationIndex); 
    // Trans flag on 100-199
    drawTransFlag(sectionLength, sectionLength * 2);
    // Rainbow on 200-299
    drawRainbowSection(sectionLength * 2, sectionLength * 3, animationIndex);
    pixels.show();
    delay(DELAYVAL);
}

// Sample function to set each letter to a different color
void setEachLetterToDifferentColor() {
    // Clear all pixels first
    pixels.clear();
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

void rainbowInEachLetter() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    pixels.clear(); // Clear all pixels first
    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        int sectionLength = end - start;
        for (int j = start; j < end; ++j) {
            // Each letter gets its own rainbow, animated by animationIndex
            pixels.setPixelColor(j, pixels.ColorHSV((int)((animationIndex + (j - start)) * (65536.0 / sectionLength))));
        }
    }
    pixels.show();
    delay(DELAYVAL);
}


void staticTransFlagInEachLetter() {
    // For each letter, draw a trans flag in its pixel range
    pixels.clear();
    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        drawTransFlag(start, end);
    }
    pixels.show();
    delay(DELAYVAL);
}

void animatedTransFlagInEachLetter() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the flag
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    pixels.clear();
    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        animatedTransFlagPattern(start, end, animationIndex, NUMPIXELS);
    }
    pixels.show();
    delay(DELAYVAL);
}
