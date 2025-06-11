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

void drawRainbowSection(int startPos, int endPos, uint16_t animationIndex, uint16_t animationCycleCount) {
    int sectionLength = endPos - startPos;
    for (int i = startPos; i < endPos; i++) {
        pixels.setPixelColor(i, pixels.ColorHSV((int)((animationIndex + i - sectionLength/2) * (65536.0 / animationCycleCount))));
    }
}