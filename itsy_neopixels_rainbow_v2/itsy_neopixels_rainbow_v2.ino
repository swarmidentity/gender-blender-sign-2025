#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        5
#define NUMPIXELS 300

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 20

// Trans flag colors (approximate)
uint32_t TRANS_BLUE = pixels.Color(91, 206, 250);
uint32_t TRANS_PINK = pixels.Color(245, 169, 184);
uint32_t TRANS_WHITE = pixels.Color(255, 255, 255);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
    //pixels.clear();
    static uint8_t rainbowHue = 0;
    rainbowHue++; // Animate the rainbow
    if (rainbowHue == 100) {
      rainbowHue = 0;
    }
    

    // Rainbow on 0-99
    for (int i = 0; i < 100; i++) {
      pixels.setPixelColor(i,pixels.ColorHSV((rainbowHue + i )  * ( 65536/100) ));
    }

    // Trans flag on 100-199
    for (int i = 100; i < 200; i++) {
        int pos = i - 100;
        if (pos < 20) {
            pixels.setPixelColor(i, TRANS_BLUE);
        } else if (pos < 40) {
            pixels.setPixelColor(i, TRANS_PINK);
        } else if (pos < 60) {
            pixels.setPixelColor(i, TRANS_WHITE);
        } else if (pos < 80) {
            pixels.setPixelColor(i, TRANS_PINK);
        } else {
            pixels.setPixelColor(i, TRANS_BLUE);
        }
    }

    // Rainbow on 200-299
    for (int i = 200; i < 300; i++) {
      pixels.setPixelColor(i,pixels.ColorHSV((rainbowHue + (i-200) )  * ( 65536/100) ));
    }

    pixels.show();
    delay(DELAYVAL);
  
}