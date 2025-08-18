int DELAYVAL = 0;
int FREQUENCY_MULTIPLIER = 1;

enum LEDPattern {
    SEPARATE_FLAG_PER_LETTER = 0,
    RAINBOW = 1,
    TRANS_FLAG_ANIMATED = 2,
    NONBINARY_FLAG_ANIMATED = 3,
    PAN_FLAG_ANIMATED = 4,
    BISEXUAL_FLAG_ANIMATED = 5,
    LESBIAN_FLAG_ANIMATED = 6,
    GENDERQUEER_FLAG_ANIMATED = 7,
    GENDERFLUID_FLAG_ANIMATED = 8,
    AGENDER_FLAG_ANIMATED = 9,
    INTERSEX_FLAG_ANIMATED = 10,
    POLYSEXUAL_FLAG_ANIMATED = 11,
    ASEXUAL_FLAG_ANIMATED = 12,
    AROMANTIC_FLAG_ANIMATED = 13,
    BIPOC_PRIDE_FLAG_ANIMATED = 14,
    TRANS_FLAG_STATIC = 15,
    RAINBOW_IN_EACH_LETTER = 16,
    ANIMATED_TRANS_FLAG_IN_EACH_LETTER = 17,
    STATIC_TRANS_FLAG_IN_EACH_LETTER = 18,
    // Add more patterns as needed
};

LEDPattern currentPattern = SEPARATE_FLAG_PER_LETTER;

void setCurrentPattern(int patternIndex) {
      currentPattern = static_cast<LEDPattern>(patternIndex);
}

void incrementCurrentPattern() {
    currentPattern = static_cast<LEDPattern>((static_cast<int>(currentPattern) + 1)
     % (STATIC_TRANS_FLAG_IN_EACH_LETTER + 1));
}

void setDelayValue(int delayValue) {
    DELAYVAL = delayValue;
}

void setFrequencyMultiplier(int frequencyMultiplier) {
    if (frequencyMultiplier < 1) {
        frequencyMultiplier = 1; // Ensure minimum value
    } else if (frequencyMultiplier > 1000) {
        frequencyMultiplier = 1000; // Ensure maximum value
    }
    FREQUENCY_MULTIPLIER = frequencyMultiplier;
}

void switchBetweenLEDControlPatterns() {
    if (currentPattern == TRANS_FLAG_STATIC) {
        staticTransFlagPattern();
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
    || (currentPattern == BIPOC_PRIDE_FLAG_ANIMATED)
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
    else {
        rainbowInEachLetter(); // Default to rainbow in each letter
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
        animateTransFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == NONBINARY_FLAG_ANIMATED) {
        animateNonbinaryFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == PAN_FLAG_ANIMATED) {
        animatePanFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == BISEXUAL_FLAG_ANIMATED) {
        animateBisexualFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == LESBIAN_FLAG_ANIMATED) {
        animateLesbianFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == GENDERQUEER_FLAG_ANIMATED) {
        animateGenderqueerFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == GENDERFLUID_FLAG_ANIMATED) {
        animateGenderfluidFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == AGENDER_FLAG_ANIMATED) {
        animateAgenderFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == INTERSEX_FLAG_ANIMATED) {
        animateIntersexFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == POLYSEXUAL_FLAG_ANIMATED) {
        animatePolysexualFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == ASEXUAL_FLAG_ANIMATED) {
        animateAsexualFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == AROMANTIC_FLAG_ANIMATED) {
        animateAromanticFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == BIPOC_PRIDE_FLAG_ANIMATED) {
        animateBlackPrideFlagPattern(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    } else if (currentPattern == RAINBOW) {
        drawRainbowSection(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER); 
    }
    else {
        // Default to rainbow if an unknown pattern is selected
        drawRainbowSection(0, NUMPIXELS, false, animationIndex, NUMPIXELS /  FREQUENCY_MULTIPLIER);
    }
    pixels.show();
    delay(DELAYVAL);
}

void rainbowInEachLetter() {
    static uint16_t animationIndex = 0;
    animationIndex++; // Animate the rainbow
    pixels.clear(); // Clear all pixels first
    for (int i = 0; i < LETTER_COUNT; ++i) {
        int start = LETTER_PIXEL_RANGES[i][0];
        int end = LETTER_PIXEL_RANGES[i][1];
        int sectionLength = end - start;
        bool isClockwise = LETTER_CLOCKWISE[i];
        for (int j = start; j < end; ++j) {
            // Each letter gets its own rainbow, animated by animationIndex
            drawRainbowSection(start, end, isClockwise, animationIndex, sectionLength / FREQUENCY_MULTIPLIER);
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
        bool isClockwise = LETTER_CLOCKWISE[i];
        animateTransFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
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
        bool isClockwise = LETTER_CLOCKWISE[i];
        if (i == 0) {
            animateTransFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 1) {
            animateBlackPrideFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 2) {
            drawRainbowSection(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER); 
        } else if (i == 3) {
            animateBisexualFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 4) {
            animateLesbianFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 5) {
            animateGenderqueerFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 6) {
            animateGenderfluidFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 7) {
            animateAgenderFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 8) {
            animateIntersexFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 9) {
            animatePanFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 10) {
            animateAsexualFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 11) {
            animateAromanticFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        } else if (i == 12) {
            animateNonbinaryFlagPattern(start, end, isClockwise, animationIndex, (end - start) / FREQUENCY_MULTIPLIER);
        }
    }
    pixels.show();
    delay(DELAYVAL);
}
