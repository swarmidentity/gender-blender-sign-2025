#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    300
#define BRIGHTNESS  128
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

// Trans flag colors (approximate)
const CRGB TRANS_BLUE  = CRGB(91, 206, 250);
const CRGB TRANS_PINK  = CRGB(245, 169, 184);
const CRGB TRANS_WHITE = CRGB(255, 255, 255);

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    static uint8_t rainbowHue = 0;
    rainbowHue++; // Animate the rainbow

    // Rainbow on 0-99
    for (int i = 0; i < 100; i++) {
        leds[i] = CHSV(rainbowHue + (i * 255 / 100), 255, 255);
    }

    // Trans flag on 100-199
    for (int i = 100; i < 200; i++) {
        int pos = i - 100;
        if (pos < 20) {
            leds[i] = TRANS_BLUE;
        } else if (pos < 40) {
            leds[i] = TRANS_PINK;
        } else if (pos < 60) {
            leds[i] = TRANS_WHITE;
        } else if (pos < 80) {
            leds[i] = TRANS_PINK;
        } else {
            leds[i] = TRANS_BLUE;
        }
    }

    // Rainbow on 200-299
    for (int i = 200; i < 300; i++) {
        leds[i] = CHSV(rainbowHue + ((i - 200) * 255 / 100), 255, 255);
    }

    FastLED.show();
    delay(20);
}