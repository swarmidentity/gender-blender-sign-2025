#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    300
#define BRIGHTNESS  120
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

// Trans flag colors (approximate)
CRGB light_blue = CRGB(91, 206, 250);
CRGB pink       = CRGB(245, 169, 184);
CRGB white      = CRGB(255, 255, 255);

const int flag_sections = 5;
int section_length = NUM_LEDS / flag_sections;
int offset = 0;

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
        int pos = (i + offset) % NUM_LEDS;
        if (pos < section_length) {
            leds[i] = light_blue;
        } else if (pos < 2 * section_length) {
            leds[i] = pink;
        } else if (pos < 3 * section_length) {
            leds[i] = white;
        } else if (pos < 4 * section_length) {
            leds[i] = pink;
        } else {
            leds[i] = light_blue;
        }
    }
    FastLED.show();
    offset = (offset + 1) % NUM_LEDS;
    delay(40);
}