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

LEDPattern currentPattern = RAINBOW;

void setCurrentPattern(int patternIndex) {
      currentPattern = static_cast<LEDPattern>(patternIndex);
}

void switchBetweenLEDControlPatterns() {
    if (currentPattern == TRANS_FLAG_STATIC) {
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
    || (currentPattern == BLACK_PRIDE_FLAG_ANIMATED)
    || (currentPattern == RAINBOW))
    {
        animateSinglePrideFlag();
    }
    else if (currentPattern == ANIMATED_TRANS_FLAG_IN_EACH_LETTER) {
        animatedTransFlagInEachLetter();
    }
    else if (currentPattern == SEPARATE_FLAG_PER_LETTER) {
        separateFlagPerLetter();
    }
}


/***************************************************************************** 
 * LED control patterns *
 *****************************************************************************/

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
    } else if (currentPattern == RAINBOW) {
        drawRainbowSection(0, NUMPIXELS, animationIndex, NUMPIXELS); 
    }
    else {
        // Default to rainbow if an unknown pattern is selected
        drawRainbowSection(0, NUMPIXELS, animationIndex, NUMPIXELS);
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
    drawRainbowSection(0, sectionLength, animationIndex, sectionLength); 
    // Trans flag on 100-199
    drawTransFlag(sectionLength, sectionLength * 2);
    // Rainbow on 200-299
    drawRainbowSection(sectionLength * 2, sectionLength * 3, animationIndex, sectionLength);
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
            drawRainbowSection(start, end, animationIndex, sectionLength);
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
            drawRainbowSection(start, end, animationIndex, NUMPIXELS); 
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
