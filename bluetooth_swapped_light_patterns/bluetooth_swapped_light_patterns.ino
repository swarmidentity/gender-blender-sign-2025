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
uint8_t AROMANTIC_LIGHT_GREEN_VALUE_BASE = 255;
uint8_t AROMANTIC_LIGHT_GREEN_VALUE_RANGE = 0; // Light Green is always 255
uint8_t AROMANTIC_DARK_GREEN_VALUE_BASE = 127; // Dark Green
uint8_t AROMANTIC_DARK_GREEN_VALUE_RANGE = 0; // Dark Green is always 50

//Black Pride Flag (Saturation instead of Hue, all in percents of 255)
//Black = 0 to 20
//Dark Brown = 20 to 40
//Medium Brown = 40 to 60
//Hue = 28, Saturation = 100
//Light Brown = 80 to 100
//Hue = 25, Saturation = 50
uint8_t BLACK_PRIDE_BLACK_VALUE_BASE = 25; 
uint8_t BLACK_PRIDE_DARK_BROWN_VALUE_BASE = 75;
uint8_t BLACK_PRIDE_MEDIUM_BROWN_VALUE_BASE = 125;
uint8_t BLACK_PRIDE_LIGHT_BROWN_VALUE_BASE = 230;
uint8_t BLACK_PRIDE_BLACK_VALUE_RANGE = 20;
uint8_t BLACK_PRIDE_DARK_BROWN_VALUE_RANGE = 20;
uint8_t BLACK_PRIDE_MEDIUM_BROWN_VALUE_RANGE = 20;
uint8_t BLACK_PRIDE_LIGHT_BROWN_VALUE_RANGE = 20;
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
    ANIMATED_TRANS_FLAG_IN_EACH_LETTER = 7,
    NONBINARY_FLAG_ANIMATED = 8,
    PAN_FLAG_ANIMATED = 9,
    BISEXUAL_FLAG_ANIMATED = 10,
    LESBIAN_FLAG_ANIMATED = 11,
    GENDERQUEER_FLAG_ANIMATED = 12,
    GENDERFLUID_FLAG_ANIMATED = 13,
    AGENDER_FLAG_ANIMATED = 14,
    INTERSEX_FLAG_ANIMATED = 15,
    POLYSEXUAL_FLAG_ANIMATED = 16,
    ASEXUAL_FLAG_ANIMATED = 17,
    AROMANTIC_FLAG_ANIMATED = 18,
    BLACK_PRIDE_FLAG_ANIMATED = 19,
    SEPARATE_FLAG_PER_LETTER = 20,
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
    else if ((currentPattern == TRANS_FLAG_ANIMATED) 
    | (currentPattern == NONBINARY_FLAG_ANIMATED)
    || (currentPattern == PAN_FLAG_ANIMATED)
    || (currentPattern == BISEXUAL_FLAG_ANIMATED)
    || (currentPattern == LESBIAN_FLAG_ANIMATED)    
    || (currentPattern == GENDERQUEER_FLAG_ANIMATED)
    || (currentPattern == GENDERFLUID_FLAG_ANIMATED)
    || (currentPattern == AGENDER_FLAG_ANIMATED)
    || (currentPattern == INTERSEX_FLAG_ANIMATED)
    || (currentPattern == POLYSEXUAL_FLAG_ANIMATED)
    || (currentPattern == ASEXUAL_FLAG_ANIMATED)
    || (currentPattern == AROMANTIC_FLAG_ANIMATED)
    || (currentPattern == BLACK_PRIDE_FLAG_ANIMATED))
    {
        animateSinglePrideFlag();
    }
    else if (currentPattern == ANIMATED_TRANS_FLAG_IN_EACH_LETTER) {
        animatedTransFlagInEachLetter();
    }
    else if (currentPattern == SEPARATE_FLAG_PER_LETTER) {
        separateFlagPerLetter();
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

void animatedStripeFlagPattern(
    int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount,
    const uint16_t* hueBase, const uint16_t* hueRange,
    const uint8_t* satBase, const uint8_t* satRange,
    const uint8_t* valBase, const uint8_t* valRange,
    int stripeCount
) {
    int length = endPos - startPos;
    int section = length / stripeCount;

    for (int j = 0; j < stripeCount; ++j) {
        int sectionStart = startPos + j * section;
        int sectionEnd = (j == stripeCount - 1) ? endPos : sectionStart + section; // Last section goes to endPos
        animateSingleColorHueSaturationValueVariation(
            sectionStart, sectionEnd,
            hueBase[j], hueRange[j],
            satBase[j], satRange[j],
            valBase[j], valRange[j],
            animationIndex, animationCycleCount
        );
    }
}

void drawRainbowSection(int startPos, int endPos, uint16_t animationIndex) {
    int sectionLength = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        pixels.setPixelColor(i, pixels.ColorHSV((int)((animationIndex + i - sectionLength/2) * (65536.0 / sectionLength))));
    }
}

/***************************************************************************** 
 * Specific Pride Flags *
 *****************************************************************************/

void animateTransFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 5;
    const uint16_t hueBase[stripeCount] = { TRANS_BLUE_HUE_BASE, TRANS_PINK_HUE_BASE, 0, TRANS_PINK_HUE_BASE, TRANS_BLUE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { TRANS_BLUE_HUE_RANGE, TRANS_PINK_HUE_RANGE, 0, TRANS_PINK_HUE_RANGE, TRANS_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 0, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, WHITE_VALUE_BASE, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, WHITE_VALUE_RANGE, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateNonbinaryFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 4;
    const uint16_t hueBase[stripeCount] = { NONBINARY_YELLOW_HUE_BASE, 0, NONBINARY_PURPLE_HUE_BASE, 0 };
    const uint16_t hueRange[stripeCount] = { NONBINARY_YELLOW_HUE_RANGE, 0, NONBINARY_PURPLE_HUE_RANGE, 0 };
    const uint8_t satBase[stripeCount] = { 255, 0, 255, 0 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, WHITE_VALUE_BASE, 255, BLACK_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { 0, WHITE_VALUE_RANGE, 0, BLACK_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animatePanFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { PAN_PINK_HUE_BASE, PAN_YELLOW_HUE_BASE, PAN_BLUE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { PAN_PINK_HUE_RANGE, PAN_YELLOW_HUE_RANGE, PAN_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateBisexualFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { BISEXUAL_PINK_HUE_BASE, BISEXUAL_BLUE_HUE_BASE, BISEXUAL_PURPLE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { BISEXUAL_PINK_HUE_RANGE, BISEXUAL_BLUE_HUE_RANGE, BISEXUAL_PURPLE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}
void animateLesbianFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 7;
    const uint16_t hueBase[stripeCount] = { LESBIAN_RED_HUE_BASE,   
        LESBIAN_DARK_ORANGE_HUE_BASE,
        LESBIAN_LIGHT_ORANGE_HUE_BASE,
        0,
        LESBIAN_MAGENTA_HUE_BASE,
        LESBIAN_DARK_PINK_HUE_BASE,
        LESBIAN_PINK_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { LESBIAN_RED_HUE_RANGE,
        LESBIAN_DARK_ORANGE_HUE_RANGE, 
        LESBIAN_LIGHT_ORANGE_HUE_RANGE,
        0,
        LESBIAN_MAGENTA_HUE_RANGE,
        LESBIAN_DARK_PINK_HUE_RANGE,
        LESBIAN_PINK_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255, 0, 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, WHITE_VALUE_BASE, 255, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, 0, WHITE_VALUE_RANGE, 0, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateGenderqueerFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { GENDERQUEER_GREEN_HUE_BASE, 0, GENDERQUEER_PURPLE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { GENDERQUEER_GREEN_HUE_RANGE, 0, GENDERQUEER_PURPLE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 0, 255 };     
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, WHITE_VALUE_BASE, 255 };
    const uint8_t valRange[stripeCount] = { 0, WHITE_VALUE_RANGE, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateGenderfluidFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 5;
    const uint16_t hueBase[stripeCount] = { GENDERFLUID_PINK_HUE_BASE, 0, GENDERFLUID_PURPLE_HUE_BASE, 0, GENDERFLUID_BLUE_HUE_BASE  };
    const uint16_t hueRange[stripeCount] = { GENDERFLUID_PINK_HUE_RANGE, 0, GENDERFLUID_PURPLE_HUE_RANGE, 0, GENDERFLUID_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 0, 255, 0, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, WHITE_VALUE_BASE, 255, BLACK_VALUE_BASE, 255 };
    const uint8_t valRange[stripeCount] = { 0, WHITE_VALUE_RANGE, 0, BLACK_VALUE_RANGE, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateAgenderFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 7;
    const uint16_t hueBase[stripeCount] = { 0, 0, 0, AGENDER_GREEN_HUE_BASE,  0, 0, 0 };
    const uint16_t hueRange[stripeCount] = { 0, 0, 0, AGENDER_GREEN_HUE_RANGE, 0, 0, 0 };
    const uint8_t satBase[stripeCount] = { 0, 0, 0, 255, 0, 0, 0 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { BLACK_VALUE_BASE, GRAY_VALUE_BASE, WHITE_VALUE_BASE, 255, WHITE_VALUE_BASE, GRAY_VALUE_BASE, BLACK_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { BLACK_VALUE_RANGE, GRAY_VALUE_RANGE, WHITE_VALUE_RANGE, 0, WHITE_VALUE_RANGE, GRAY_VALUE_RANGE, BLACK_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateIntersexFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { INTERSEX_YELLOW_HUE_BASE, INTERSEX_PURPLE_HUE_BASE, INTERSEX_YELLOW_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { INTERSEX_YELLOW_HUE_RANGE, INTERSEX_PURPLE_HUE_RANGE, INTERSEX_YELLOW_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);     
}

void animatePolysexualFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { POLYSEXUAL_PINK_HUE_BASE, POLYSEXUAL_GREEN_HUE_BASE, POLYSEXUAL_BLUE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { POLYSEXUAL_PINK_HUE_RANGE, POLYSEXUAL_GREEN_HUE_RANGE, POLYSEXUAL_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateAsexualFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 4;
    const uint16_t hueBase[stripeCount] = { 0, 0, 0, ASEXUAL_PURPLE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { 0, 0, 0, ASEXUAL_PURPLE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 0, 0, 0, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { BLACK_VALUE_BASE, GRAY_VALUE_BASE, WHITE_VALUE_BASE, 255 };
    const uint8_t valRange[stripeCount] = { BLACK_VALUE_RANGE, GRAY_VALUE_RANGE, WHITE_VALUE_RANGE, 0 };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateAromanticFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 5;
    const uint16_t hueBase[stripeCount] = {AROMANTIC_GREEN_HUE_BASE, AROMANTIC_GREEN_HUE_BASE, 0, 0, 0};
    const uint16_t hueRange[stripeCount] = {AROMANTIC_GREEN_HUE_RANGE, AROMANTIC_GREEN_HUE_RANGE, 0, 0, 0};
    const uint8_t satBase[stripeCount] = {255, 255, 0, 0, 0};
    const uint8_t satRange[stripeCount] = {0, 0, 0, 0, 0};
    const uint8_t valBase[stripeCount] = {AROMANTIC_LIGHT_GREEN_VALUE_BASE, AROMANTIC_DARK_GREEN_VALUE_BASE, WHITE_VALUE_BASE, GRAY_VALUE_BASE, BLACK_VALUE_BASE};
    const uint8_t valRange[stripeCount] = {AROMANTIC_LIGHT_GREEN_VALUE_RANGE, AROMANTIC_DARK_GREEN_VALUE_RANGE, WHITE_VALUE_RANGE, GRAY_VALUE_RANGE, BLACK_VALUE_RANGE};
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount); 
}

void animateBlackPrideFlagPattern(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 4;
    const uint16_t hueBase[stripeCount] = { BLACK_PRIDE_LIGHT_HUE, BLACK_PRIDE_DARK_HUE, BLACK_PRIDE_DARK_HUE, BLACK_PRIDE_DARK_HUE };
    const uint16_t hueRange[stripeCount] = { 0,0,0,0 };
    const uint8_t satBase[stripeCount] = { BLACK_PRIDE_LIGHT_SATURATION, BLACK_PRIDE_DARK_SATURATION, BLACK_PRIDE_DARK_SATURATION, BLACK_PRIDE_DARK_SATURATION };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { BLACK_PRIDE_LIGHT_BROWN_VALUE_BASE, BLACK_PRIDE_MEDIUM_BROWN_VALUE_BASE, BLACK_PRIDE_DARK_BROWN_VALUE_BASE , BLACK_PRIDE_BLACK_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { BLACK_PRIDE_LIGHT_BROWN_VALUE_RANGE, BLACK_PRIDE_MEDIUM_BROWN_VALUE_RANGE, BLACK_PRIDE_DARK_BROWN_VALUE_RANGE, BLACK_PRIDE_BLACK_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
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

void animateSinglePrideFlag() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    if (currentPattern == TRANS_FLAG_ANIMATED) {
        animateTransFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == NONBINARY_FLAG_ANIMATED) {
        animateNonbinaryFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == PAN_FLAG_ANIMATED) {
        animatePanFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == BISEXUAL_FLAG_ANIMATED) {
        animateBisexualFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == LESBIAN_FLAG_ANIMATED) {
        animateLesbianFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == GENDERQUEER_FLAG_ANIMATED) {
        animateGenderqueerFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == GENDERFLUID_FLAG_ANIMATED) {
        animateGenderfluidFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == AGENDER_FLAG_ANIMATED) {
        animateAgenderFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == INTERSEX_FLAG_ANIMATED) {
        animateIntersexFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == POLYSEXUAL_FLAG_ANIMATED) {
        animatePolysexualFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == ASEXUAL_FLAG_ANIMATED) {
        animateAsexualFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == AROMANTIC_FLAG_ANIMATED) {
        animateAromanticFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } else if (currentPattern == BLACK_PRIDE_FLAG_ANIMATED) {
        animateBlackPrideFlagPattern(0, NUMPIXELS, animationIndex, NUMPIXELS);
    } 
    else {
        // Default to rainbow if an unknown pattern is selected
        drawRainbowSection(0, NUMPIXELS, animationIndex);
    }
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
        animateTransFlagPattern(start, end, animationIndex, NUMPIXELS);
    }
    pixels.show();
    delay(DELAYVAL);
}

void separateFlagPerLetter() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the flags
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    
    pixels.clear(); // Clear all pixels first
    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        if (i == 0) {
            animateTransFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 1) {
            animateBlackPrideFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 2) {
            drawRainbowSection(start, end, animationIndex); 
        } else if (i == 3) {
            animateBisexualFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 4) {
            animateLesbianFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 5) {
            animateGenderqueerFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 6) {
            animateGenderfluidFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 7) {
            animateAgenderFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 8) {
            animateIntersexFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 9) {
            animatePanFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 10) {
            animateAsexualFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 11) {
            animateAromanticFlagPattern(start, end, animationIndex, NUMPIXELS);
        } else if (i == 12) {
            animateNonbinaryFlagPattern(start, end, animationIndex, NUMPIXELS);
        }
    }
    pixels.show();
    delay(DELAYVAL);
}
