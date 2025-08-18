void setupBluetooth() {
    //Serial.begin(115200);
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  //Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
}

bool isPatternLocked = false;


void checkForNewBluetoothCommands() {
  if (SerialBT.available()&& !isPatternLocked) {
      String incomingString = SerialBT.readString();
      incomingString.trim(); 
      selectDebugState(incomingString);
  }
}

/***************************************************************************** 
 * Debug Mode Functions *
 *****************************************************************************

 # [##] - Set all pixels to a single color (Hex Color Code)
 * [P#] - Show a single pixel at index #
 * [Rstart-end-hexColor] - Set a range of pixels to a hex color
 * [M#] - Set the current pattern to # (0 to 13)
 * [N] - Increment the current pattern
 * [B#] - Set the brightness to # (0 to 255)
 * [D#] - Set Delay to # (in milliseconds)
 * [F#] - Set Frequency Multiplier
 * [LOCK] - Lock current pattern
 * [?] - Output list of available commands
 */

void selectDebugState(String incomingString) {
    if (incomingString.startsWith("#")) {
        incomingString.remove(0, 1); // Remove "#"
        incomingString.trim();
        setAllToSameColor(incomingString);
        inDebugMode = true;
    }
    else if (incomingString.startsWith("P")) {
        incomingString.remove(0, 1); // Remove "P"
        incomingString.trim();
        int ledIndex = incomingString.toInt();
        showSinglePixel(ledIndex);
        inDebugMode = true;
    }
    else if (incomingString.startsWith("R")) {
        incomingString.remove(0, 1); // Remove "R"
        //Expected format will be "R[start]-[end]-[hexColor]"
        int dashIndex = incomingString.indexOf('-');
        if (dashIndex != -1) {
            int start = incomingString.substring(0, dashIndex).toInt();
            incomingString.remove(0, dashIndex + 1); // Remove up to the first
            dashIndex = incomingString.indexOf('-');
            if (dashIndex != -1) {
                int end = incomingString.substring(0, dashIndex).toInt();
                incomingString.remove(0, dashIndex + 1); // Remove up to the second
                setRangeToHexColor(start, end, incomingString);
                inDebugMode = true;
            }
        }
    }
    else if (incomingString.startsWith("M")) {
        incomingString.remove(0, 1); // Remove "M"
        incomingString.trim();
        int patternIndex = incomingString.toInt();
        setCurrentPattern(patternIndex);
        inDebugMode = false;
    }
    else if (incomingString.startsWith("N")) {
        incrementCurrentPattern();
        inDebugMode = false;
    }
    else if (incomingString.startsWith("B")) {
        incomingString.remove(0, 1); // Remove "B"
        incomingString.trim();
        int brightness = incomingString.toInt();
        setCurrentBrightness(brightness);
    }
    else if (incomingString.startsWith("D")) {
        incomingString.remove(0, 1); // Remove "D"
        incomingString.trim();
        int delayValue = incomingString.toInt();
        setDelayValue(delayValue);
    }
    else if (incomingString.startsWith("F")) {
        incomingString.remove(0, 1); // Remove "F"
        incomingString.trim();
        int frequencyMultiplier = incomingString.toInt();
        setFrequencyMultiplier(frequencyMultiplier);
    }
    else if (incomingString.startsWith("LOCK")) {
        isPatternLocked = true; // Lock the current pattern
    }
    else if (incomingString.startsWith("?")) {
        SerialBT.println("Available commands:");
        SerialBT.println("? - Output list of available commands (but you already know that)");
        SerialBT.println("#[HexColor] - Set all pixels to a single color");
        SerialBT.println("P# - Show a single pixel at index #");
        SerialBT.println("R[start]-[end]-[hexColor] - Set a range of pixels to a hex color");
        SerialBT.println("B# - Set the brightness to # (0 to 255)");
        SerialBT.println("D# - Set Delay to # (in milliseconds)");
        SerialBT.println("F# - Set Frequency Multiplier (1 to 1000) - higher = more manic");
        SerialBT.println("N - Increment the current pattern");
        SerialBT.println("M# - Set the current pattern to # (0 to 118)");
        SerialBT.println("Patterns:");
        SerialBT.println("M0 = SEPARATE_FLAG_PER_LETTER");
        SerialBT.println("M1 = RAINBOW");
        SerialBT.println("M2 = TRANS_FLAG_ANIMATED");
        SerialBT.println("M3 = NONBINARY_FLAG_ANIMATED");
        SerialBT.println("M4 = PAN_FLAG_ANIMATED");
        SerialBT.println("M5 = BISEXUAL_FLAG_ANIMATED");
        SerialBT.println("M6 = LESBIAN_FLAG_ANIMATED");
        SerialBT.println("M7 = GENDERQUEER_FLAG_ANIMATED");
        SerialBT.println("M8 = GENDERFLUID_FLAG_ANIMATED");
        SerialBT.println("M9 = AGENDER_FLAG_ANIMATED");
        SerialBT.println("M10 = INTERSEX_FLAG_ANIMATED");
        SerialBT.println("M11 = POLYSEXUAL_FLAG_ANIMATED");
        SerialBT.println("M12 = ASEXUAL_FLAG_ANIMATED");
        SerialBT.println("M13 = AROMANTIC_FLAG_ANIMATED");
        SerialBT.println("M14 = BIPOC_PRIDE_FLAG_ANIMATED");
        SerialBT.println("M15 = TRANS_FLAG_STATIC");
        SerialBT.println("M16 = RAINBOW_IN_EACH_LETTER");
        SerialBT.println("M17 = ANIMATED_TRANS_FLAG_IN_EACH_LETTER");
        SerialBT.println("M18 = STATIC_TRANS_FLAG_IN_EACH_LETTER");
        SerialBT.println("--Nai1s--");
    }
    else {
        inDebugMode = false;
    }
}
