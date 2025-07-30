int DELAYVAL = 100;

enum LEDPattern {
    RAINBOW,
    TRANS_FLAG_STATIC,
    TRANS_FLAG_ANIMATED,
    NONBINARY_FLAG_ANIMATED,
    PAN_FLAG_ANIMATED,
    BISEXUAL_FLAG_ANIMATED,
    LESBIAN_FLAG_ANIMATED,
    GENDERQUEER_FLAG_ANIMATED,
    GENDERFLUID_FLAG_ANIMATED,
    AGENDER_FLAG_ANIMATED,
    INTERSEX_FLAG_ANIMATED,
    POLYSEXUAL_FLAG_ANIMATED,
    ASEXUAL_FLAG_ANIMATED,
    AROMANTIC_FLAG_ANIMATED,
};

LEDPattern currentPattern = RAINBOW;

void setCurrentPattern(int patternIndex) {
      currentPattern = static_cast<LEDPattern>(patternIndex);
}

void incrementCurrentPattern() {
    currentPattern = static_cast<LEDPattern>((static_cast<int>(currentPattern) + 1)
     % (AROMANTIC_FLAG_ANIMATED + 1));
}

void setDelayValue(int delayValue) {
    DELAYVAL = delayValue;
}

void switchBetweenLEDControlPatterns() {
    if (currentPattern == TRANS_FLAG_STATIC) {
        staticTransFlagPattern();
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
    || (currentPattern == RAINBOW))
    {
        animateSinglePrideFlag();
    }
    else {
        rainbowInEachLetter(); // Default to rainbow in each letter
    }
}


/***************************************************************************** 
 * LED control patterns *
 *****************************************************************************/

void staticTransFlagPattern() {
    drawTransFlag(0, NUMPIXELS);
    delay(DELAYVAL);
}

void animateSinglePrideFlag() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    uint16_t animationCycleCount = 255; // Total number of pixels for animation
    if (animationIndex == animationCycleCount) {
      animationIndex = 0;
    }
    if (currentPattern == TRANS_FLAG_ANIMATED) {
        animateTransFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == NONBINARY_FLAG_ANIMATED) {
        animateNonbinaryFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == PAN_FLAG_ANIMATED) {
        animatePanFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == BISEXUAL_FLAG_ANIMATED) {
        animateBisexualFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == LESBIAN_FLAG_ANIMATED) {
        animateLesbianFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == GENDERQUEER_FLAG_ANIMATED) {
        animateGenderqueerFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == GENDERFLUID_FLAG_ANIMATED) {
        animateGenderfluidFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == AGENDER_FLAG_ANIMATED) {
        animateAgenderFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == INTERSEX_FLAG_ANIMATED) {
        animateIntersexFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == POLYSEXUAL_FLAG_ANIMATED) {
        animatePolysexualFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == ASEXUAL_FLAG_ANIMATED) {
        animateAsexualFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == AROMANTIC_FLAG_ANIMATED) {
        animateAromanticFlagPattern(0, NUMPIXELS, animationIndex, animationCycleCount);
    } else if (currentPattern == RAINBOW) {
        if (animationIndex == NUMPIXELS) {
            animationIndex = 0; // Reset animation index to loop
        }
        drawRainbowSection(0, NUMPIXELS, animationIndex, NUMPIXELS); 
    }
    else {
        // Default to rainbow if an unknown pattern is selected
        drawRainbowSection(0, NUMPIXELS, animationIndex, NUMPIXELS);
    }
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
    delay(DELAYVAL);
}

void separateFlagPerLetter() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the flags
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    
    pixels.clear(); // Clear all pixels first

    //TODO - if adding any reactivity (such as sound), the animationCycleCount is a good place for it
    uint16_t animationCycleCount = NUMPIXELS; 

    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        if (i == 0) {
            animateTransFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 1) {
            animateBlackPrideFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 2) {
            drawRainbowSection(start, end, animationIndex, animationCycleCount / 3); 
        } else if (i == 3) {
            animateBisexualFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 4) {
            animateLesbianFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 5) {
            animateGenderqueerFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 6) {
            animateGenderfluidFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 7) {
            animateAgenderFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 8) {
            animateIntersexFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 9) {
            animatePanFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 10) {
            animateAsexualFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 11) {
            animateAromanticFlagPattern(start, end, animationIndex, animationCycleCount);
        } else if (i == 12) {
            animateNonbinaryFlagPattern(start, end, animationIndex, animationCycleCount);
        }
    }
    delay(DELAYVAL);
}

void rainbowInOneLetter() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    if (animationIndex == NUMPIXELS) {
      animationIndex = 0;
    }
    
    pixels.clear(); // Clear all pixels first

    // Draw a rainbow in the last letter's pixel range
    int start = LETTER_PIXEL_RANGES[LETTER_COUNT - 1][0];
    int end = LETTER_PIXEL_RANGES[LETTER_COUNT - 1][1];
    drawRainbowSection(start, end, animationIndex, end - start);
    
    delay(DELAYVAL);
}