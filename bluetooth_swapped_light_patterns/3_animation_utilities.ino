/***************************************************************************** 
 * Utility functions for drawing patterns *
 *****************************************************************************/

int currentBrightness = 255;

void setPixelClockwiseAdjusted(int pixel, uint32_t colorCode) {
    for (int letterIdx = 0; letterIdx < LETTER_COUNT; ++letterIdx) {
        int letterStart = LETTER_PIXEL_RANGES[letterIdx][0];
        int letterEnd = LETTER_PIXEL_RANGES[letterIdx][1];
        if (pixel >= letterStart && pixel < letterEnd) {
            bool isClockwise = LETTER_CLOCKWISE[letterIdx];
            int adjustedPixel = isClockwise ? (pixel - letterStart) : (letterEnd - 1 - pixel);
            int mappedPixel = letterStart + adjustedPixel;
            pixels.setPixelColor(mappedPixel, colorCode);
            break;
        }
    }

}

void drawTransFlag(int startPos, int endPos) {
    int length = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        float posNorm = float(i - startPos) / float(length);
        if (posNorm < 0.2f) {
            setPixelClockwiseAdjusted(i, TRANS_BLUE);
        } else if (posNorm < 0.4f) {
            setPixelClockwiseAdjusted(i, TRANS_PINK);
        } else if (posNorm < 0.6f) {
            setPixelClockwiseAdjusted(i, TRANS_WHITE);
        } else if (posNorm < 0.8f) {
            setPixelClockwiseAdjusted(i, TRANS_PINK);
        } else {
            setPixelClockwiseAdjusted(i, TRANS_BLUE);
        }
    }
}

void animateSingleColorHueSaturationValueVariation(int startPos, int endPos, bool isClockwise,
    uint16_t baseHue, uint16_t hueRange, 
    uint8_t baseSaturation, uint8_t saturationRange, 
    uint8_t baseValue, uint8_t valueRange, 
    uint16_t animationIndex, uint16_t animationCycleCount) {
    int length = endPos - startPos;
    for (int i = startPos; i < endPos; ++i) {
        int pos = i - startPos;
        float localPhase = 0.0f;
        uint32_t color = 0;

        int clockwiseAdjustedPos = animationIndex + pos;
        //Attempted this algorithm, removing
        // if (!isClockwise) {
        //     clockwiseAdjustedPos = animationIndex - pos;
        // }
        
        // Use animationIndex as the animation driver
        // Offset by pixel for wave
        localPhase = (float)(((clockwiseAdjustedPos)) * (360.0f/animationCycleCount)) / 90.0f;
        float s = (sin(localPhase * 2.0f * PI) + 1.0f) / 2.0f;

        uint16_t hue = baseHue - hueRange/2 + (uint16_t)(hueRange * s);
        uint8_t saturation = baseSaturation - saturationRange/2 + (uint8_t)(saturationRange * s);
        uint8_t value = baseValue - valueRange/2 + (uint8_t)(valueRange * s);
        color = pixels.ColorHSV(hue, saturation, value);
        setPixelClockwiseAdjusted(i, color);
    }
}

void animatedStripeFlagPattern(
    int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount,
    const uint16_t* hueBase, const uint16_t* hueRange,
    const uint8_t* satBase, const uint8_t* satRange,
    const uint8_t* valBase, const uint8_t* valRange,
    int stripeCount
) {
    int length = endPos - startPos;
    float section = float(length) / float(stripeCount);

    for (int j = 0; j < stripeCount; ++j) {
        int sectionStart = startPos + int(j * section);
        int sectionEnd = (j == stripeCount - 1) ? endPos : sectionStart + section; // Last section goes to endPos
        animateSingleColorHueSaturationValueVariation(
            sectionStart, sectionEnd, isClockwise,
            hueBase[j], hueRange[j],
            satBase[j], satRange[j],
            valBase[j], valRange[j],
            animationIndex, animationCycleCount
        );
    }
}

void drawRainbowSection(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    int sectionLength = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        int clockwiseAdjustedPos = animationIndex + i - sectionLength/2;
        //Attempted this algorithm, removing
        // if (!isClockwise) {
        //     clockwiseAdjustedPos = animationIndex - i - sectionLength/2;
        // }
        setPixelClockwiseAdjusted(i, pixels.ColorHSV((int)((clockwiseAdjustedPos) * (65536.0 / animationCycleCount))));
    }
}

void setCurrentBrightness(int brightness) {
    currentBrightness = brightness;
    if (brightness < 0) currentBrightness = 0;
    if (brightness > 255) currentBrightness = 255;
}

void setAllPixelsBrightness() {
    pixels.setBrightness(currentBrightness);
    pixels.show();
}