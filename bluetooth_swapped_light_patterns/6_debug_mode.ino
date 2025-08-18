bool inDebugMode = false;

bool isInDebugMode() {
    return inDebugMode;
}

void showSinglePixel(int ledIndex) {
  pixels.clear();
  if (ledIndex >= 0 && ledIndex < NUMPIXELS) {
    pixels.setPixelColor(ledIndex, pixels.Color(255, 255, 255)); // White
  }
}

void setAllToSameColor(String hexColor) {
    uint32_t color = hexToColor(hexColor);
    pixels.clear();
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, color);
    }
}

void setRangeToHexColor(int start, int end, String hexColor) {
    uint32_t color = hexToColor(hexColor);
    for (int i = start; i <= end && i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, color);
    }
}

uint32_t hexToColor(String hexColor) {
    long number = strtol(&hexColor[0], NULL, 16);
    return pixels.Color((number >> 16) & 0xFF, (number >> 8) & 0xFF, number & 0xFF);
}