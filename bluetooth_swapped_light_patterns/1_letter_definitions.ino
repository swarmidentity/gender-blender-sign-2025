
const int LETTER_COUNT = 13;

// Start and end pixel indices for each letter in "GENDERBLENDER"
// Example: {start, end} for each letter (inclusive start, exclusive end)
const int LETTER_PIXEL_RANGES[LETTER_COUNT][2] = {
    {0, 62},    // G
    {63, 117},   // E
    {118, 175},   // N
    {176, 246},   // D
    {247, 296},  // E
    {297, 349}, // R
    {350, 421}, // B
    {422, 456}, // L
    {457, 507}, // E
    {508, 563}, // N
    {564, 631}, // D
    {632, 683}, // E
    {684, 737}  // R
};

// Direction for each letter: true = clockwise, false = counterclockwise
const bool LETTER_CLOCKWISE[LETTER_COUNT] = {
    true,   // G
    true,  // E
    false,   // N
    false,  // D
    true,   // E
    false,  // R
    true,   // B
    true,  // L
    false,   // E
    false,  // N
    false,   // D
    true,  // E
    false    // R
};

// Optional: Character labels for reference
const char* LETTER_LABELS[LETTER_COUNT] = {
    "G", "E", "N", "D", "E", "R", "B", "L", "E", "N", "D", "E", "R"
};

// Debug Colors for Letters - used for aligning
const uint32_t LETTER_COLORS[LETTER_COUNT] = {
    pixels.Color(255, 0, 0),    // Red
    pixels.Color(255, 128, 0),  // Orange
    pixels.Color(255, 255, 0),  // Yellow
    pixels.Color(0, 255, 0),    // Green
    pixels.Color(0, 255, 255),  // Cyan
    pixels.Color(0, 0, 255),    // Blue
    pixels.Color(128, 0, 255),  // Purple
    pixels.Color(255, 0, 255),  // Magenta
    pixels.Color(255, 0, 128),  // Pink
    pixels.Color(128, 128, 128),// Gray
    pixels.Color(255, 255, 255),// White
    pixels.Color(128, 64, 0),   // Brown
    pixels.Color(50, 50, 50)       // Dark Grey
};