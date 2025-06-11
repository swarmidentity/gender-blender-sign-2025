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
//Green = 110 to 130
//Purple = 260 to 280
uint16_t GENDERQUEER_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t GENDERQUEER_PURPLE_HUE_BASE = (65536 * 270 ) / 360;
uint16_t GENDERQUEER_GREEN_HUE_RANGE = (uint16_t)((65536 * 20)/360);
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
//Green = 110 to 130
uint16_t AGENDER_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t AGENDER_GREEN_HUE_RANGE = (uint16_t)((65536 * 20)/360);

//Intersex Flag
//Yellow = 50 to 65
//Purple = 265 to 285
uint16_t INTERSEX_YELLOW_HUE_BASE = (65536 * 57 ) / 360;
uint16_t INTERSEX_PURPLE_HUE_BASE = (65536 * 275 ) / 360;
uint16_t INTERSEX_YELLOW_HUE_RANGE = (uint16_t)((65536 * 15)/360);
uint16_t INTERSEX_PURPLE_HUE_RANGE = (uint16_t)((65536 * 20)/360);

//Polysexual Flag
//Pink = 280 to 330
//Green = 110 to 130
//Blue = 200 to 260
uint16_t POLYSEXUAL_PINK_HUE_BASE = (65536 * 310 ) / 360;
uint16_t POLYSEXUAL_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t POLYSEXUAL_BLUE_HUE_BASE = (65536 * 230 ) / 360;
uint16_t POLYSEXUAL_PINK_HUE_RANGE = (uint16_t)((65536 * 50)/360);
uint16_t POLYSEXUAL_GREEN_HUE_RANGE = (uint16_t)((65536 * 20)/360);
uint16_t POLYSEXUAL_BLUE_HUE_RANGE = (uint16_t)((65536 * 60)/360);

//Asexual Flag
//Purple = 260 to 270
uint16_t ASEXUAL_PURPLE_HUE_BASE = (65536 * 265 ) / 360;
uint16_t ASEXUAL_PURPLE_HUE_RANGE = (uint16_t)((65536 * 10)/360);

//Aromantic Flag
//Green = 110 to 130
uint16_t AROMANTIC_GREEN_HUE_BASE = (65536 * 120 ) / 360;
uint16_t AROMANTIC_GREEN_HUE_RANGE = (uint16_t)((65536 * 20)/360);
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
uint8_t BLACK_PRIDE_LIGHT_BROWN_VALUE_BASE = 150;
uint8_t BLACK_PRIDE_BLACK_VALUE_RANGE = 50;
uint8_t BLACK_PRIDE_DARK_BROWN_VALUE_RANGE = 75;
uint8_t BLACK_PRIDE_MEDIUM_BROWN_VALUE_RANGE = 75;
uint8_t BLACK_PRIDE_LIGHT_BROWN_VALUE_RANGE = 50;
uint16_t BLACK_PRIDE_DARK_HUE = (65536 * 28 ) / 360; // Dark Brown
uint16_t BLACK_PRIDE_LIGHT_HUE = (65536 * 25 ) / 360; // Medium Brown
uint16_t BLACK_PRIDE_DARK_SATURATION = 255;
uint16_t BLACK_PRIDE_LIGHT_SATURATION = 127;


//White, Gray and Black Colors (Value instead of Hue, all in percents of 255)
//White = 80 to 100
//Gray = 60 to 80
//Black = 0 to 40
uint8_t WHITE_VALUE_BASE = 200; // White
uint8_t GRAY_VALUE_BASE = 150; // Gray
uint8_t BLACK_VALUE_BASE = 50; // Black
uint8_t WHITE_VALUE_RANGE = 110; // White
uint8_t GRAY_VALUE_RANGE = 110; // Gray
uint8_t BLACK_VALUE_RANGE = 100; // Black

// Use Extra value changes to Base/Range when a color isn't visibly changing

uint8_t EXTRA_POP_VALUE_BASE = 150; 
uint8_t EXTRA_POP_VALUE_RANGE = 110; 