
/***************************************************************************** 
 * Specific Pride Flags *
 *****************************************************************************/

void animateTransFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 5;
    const uint16_t hueBase[stripeCount] = { TRANS_BLUE_HUE_BASE, TRANS_PINK_HUE_BASE, 0, TRANS_PINK_HUE_BASE, TRANS_BLUE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { TRANS_BLUE_HUE_RANGE, TRANS_PINK_HUE_RANGE, 0, TRANS_PINK_HUE_RANGE, TRANS_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 0, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, WHITE_VALUE_BASE, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, WHITE_VALUE_RANGE, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateNonbinaryFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 4;
    const uint16_t hueBase[stripeCount] = { NONBINARY_YELLOW_HUE_BASE, 0, NONBINARY_PURPLE_HUE_BASE, 0 };
    const uint16_t hueRange[stripeCount] = { NONBINARY_YELLOW_HUE_RANGE, 0, NONBINARY_PURPLE_HUE_RANGE, 0 };
    const uint8_t satBase[stripeCount] = { 255, 0, 255, 0 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { EXTRA_POP_VALUE_BASE, WHITE_VALUE_BASE, 255, BLACK_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { EXTRA_POP_VALUE_RANGE, WHITE_VALUE_RANGE, 0, BLACK_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animatePanFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { PAN_PINK_HUE_BASE, PAN_YELLOW_HUE_BASE, PAN_BLUE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { PAN_PINK_HUE_RANGE, PAN_YELLOW_HUE_RANGE, PAN_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateBisexualFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { BISEXUAL_PINK_HUE_BASE, BISEXUAL_BLUE_HUE_BASE, BISEXUAL_PURPLE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { BISEXUAL_PINK_HUE_RANGE, BISEXUAL_BLUE_HUE_RANGE, BISEXUAL_PURPLE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, 255, 255 };
    const uint8_t valRange[stripeCount] = { 0, 0, 0 };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}
void animateLesbianFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
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
    const uint8_t valBase[stripeCount] = { EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE, WHITE_VALUE_BASE, EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE, WHITE_VALUE_RANGE, EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateGenderqueerFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { GENDERQUEER_GREEN_HUE_BASE, 0, GENDERQUEER_PURPLE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { GENDERQUEER_GREEN_HUE_RANGE, 0, GENDERQUEER_PURPLE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 0, 255 };     
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { 255, WHITE_VALUE_BASE, 255 };
    const uint8_t valRange[stripeCount] = { 0, WHITE_VALUE_RANGE, 0 };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateGenderfluidFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 5;
    const uint16_t hueBase[stripeCount] = { GENDERFLUID_PINK_HUE_BASE, 0, GENDERFLUID_PURPLE_HUE_BASE, 0, GENDERFLUID_BLUE_HUE_BASE  };
    const uint16_t hueRange[stripeCount] = { GENDERFLUID_PINK_HUE_RANGE, 0, GENDERFLUID_PURPLE_HUE_RANGE, 0, GENDERFLUID_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 0, 255, 0, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { EXTRA_POP_VALUE_BASE, WHITE_VALUE_BASE, 255, BLACK_VALUE_BASE, 255 };
    const uint8_t valRange[stripeCount] = { EXTRA_POP_VALUE_RANGE, WHITE_VALUE_RANGE, 0, BLACK_VALUE_RANGE, 0 };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateAgenderFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 7;
    const uint16_t hueBase[stripeCount] = { 0, 0, 0, AGENDER_GREEN_HUE_BASE,  0, 0, 0 };
    const uint16_t hueRange[stripeCount] = { 0, 0, 0, AGENDER_GREEN_HUE_RANGE, 0, 0, 0 };
    const uint8_t satBase[stripeCount] = { 0, 0, 0, 255, 0, 0, 0 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { BLACK_VALUE_BASE, GRAY_VALUE_BASE, WHITE_VALUE_BASE, 255, WHITE_VALUE_BASE, GRAY_VALUE_BASE, BLACK_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { BLACK_VALUE_RANGE, GRAY_VALUE_RANGE, WHITE_VALUE_RANGE, 0, WHITE_VALUE_RANGE, GRAY_VALUE_RANGE, BLACK_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateIntersexFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { INTERSEX_YELLOW_HUE_BASE, INTERSEX_PURPLE_HUE_BASE, INTERSEX_YELLOW_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { INTERSEX_YELLOW_HUE_RANGE, INTERSEX_PURPLE_HUE_RANGE, INTERSEX_YELLOW_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE, EXTRA_POP_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE, EXTRA_POP_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);     
}

void animatePolysexualFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { POLYSEXUAL_PINK_HUE_BASE, POLYSEXUAL_GREEN_HUE_BASE, POLYSEXUAL_BLUE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { POLYSEXUAL_PINK_HUE_RANGE, POLYSEXUAL_GREEN_HUE_RANGE, POLYSEXUAL_BLUE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 255, 255, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { EXTRA_POP_VALUE_BASE, 255, EXTRA_POP_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { EXTRA_POP_VALUE_RANGE, 0, EXTRA_POP_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateAsexualFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 4;
    const uint16_t hueBase[stripeCount] = { 0, 0, 0, ASEXUAL_PURPLE_HUE_BASE };
    const uint16_t hueRange[stripeCount] = { 0, 0, 0, ASEXUAL_PURPLE_HUE_RANGE };
    const uint8_t satBase[stripeCount] = { 0, 0, 0, 255 };
    const uint8_t satRange[stripeCount] = { 0, 0, 0, 0 };
    const uint8_t valBase[stripeCount] = { BLACK_VALUE_BASE, GRAY_VALUE_BASE, WHITE_VALUE_BASE, EXTRA_POP_VALUE_BASE };
    const uint8_t valRange[stripeCount] = { BLACK_VALUE_RANGE, GRAY_VALUE_RANGE, WHITE_VALUE_RANGE, EXTRA_POP_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}

void animateAromanticFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 5;
    const uint16_t hueBase[stripeCount] = {AROMANTIC_GREEN_HUE_BASE, AROMANTIC_GREEN_HUE_BASE, 0, 0, 0};
    const uint16_t hueRange[stripeCount] = {AROMANTIC_GREEN_HUE_RANGE, AROMANTIC_GREEN_HUE_RANGE, 0, 0, 0};
    const uint8_t satBase[stripeCount] = {255, 255, 0, 0, 0};
    const uint8_t satRange[stripeCount] = {0, 0, 0, 0, 0};
    const uint8_t valBase[stripeCount] = {AROMANTIC_LIGHT_GREEN_VALUE_BASE, AROMANTIC_DARK_GREEN_VALUE_BASE, WHITE_VALUE_BASE, GRAY_VALUE_BASE, BLACK_VALUE_BASE};
    const uint8_t valRange[stripeCount] = {AROMANTIC_LIGHT_GREEN_VALUE_RANGE, AROMANTIC_DARK_GREEN_VALUE_RANGE, WHITE_VALUE_RANGE, GRAY_VALUE_RANGE, BLACK_VALUE_RANGE};
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount); 
}

void animateBlackPrideFlagPattern(int startPos, int endPos, bool isClockwise, uint16_t animationIndex, uint16_t animationCycleCount) {
    const int stripeCount = 3;
    const uint16_t hueBase[stripeCount] = { BLACK_PRIDE_DARK_HUE, BLACK_PRIDE_DARK_HUE, BLACK_PRIDE_DARK_HUE };
    const uint16_t hueRange[stripeCount] = { 0,0,0 };
    const uint8_t satBase[stripeCount] = { BLACK_PRIDE_DARK_SATURATION, BLACK_PRIDE_DARK_SATURATION, BLACK_PRIDE_DARK_SATURATION };
    const uint8_t satRange[stripeCount] = { 0, 0, 0 };
    const uint8_t valBase[stripeCount] = {  BLACK_PRIDE_MEDIUM_BROWN_VALUE_BASE, BLACK_PRIDE_DARK_BROWN_VALUE_BASE , BLACK_PRIDE_BLACK_VALUE_BASE };
    const uint8_t valRange[stripeCount] = {  BLACK_PRIDE_MEDIUM_BROWN_VALUE_RANGE, BLACK_PRIDE_DARK_BROWN_VALUE_RANGE, BLACK_PRIDE_BLACK_VALUE_RANGE };
    animatedStripeFlagPattern(startPos, endPos, isClockwise,animationIndex, animationCycleCount, hueBase, hueRange, satBase, satRange, valBase, valRange, stripeCount);
}