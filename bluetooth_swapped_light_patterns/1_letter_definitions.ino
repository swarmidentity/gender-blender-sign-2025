
const int LETTER_COUNT = 13;

// Start and end pixel indices for each letter in "GENDERBLENDER"
// Example: {start, end} for each letter (inclusive start, exclusive end)
const int LETTER_PIXEL_RANGES[LETTER_COUNT][2] = {
    {0, 62},    // G
    {63, 64},   // E
    {65, 66},   // N
    {66, 86},   // D
    {88, 108},  // E
    {110, 130}, // R
    {132, 152}, // B
    {154, 174}, // L
    {176, 196}, // E
    {198, 218}, // N
    {220, 240}, // D
    {242, 264}, // E
    {272, 294}  // R
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