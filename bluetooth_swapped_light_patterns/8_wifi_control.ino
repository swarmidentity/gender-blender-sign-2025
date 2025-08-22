bool isPatternLocked = false;


String reactToNewWifiCommand(String userText) {
      String incomingString = userText;
      incomingString.trim(); 
      return selectDebugState(incomingString);
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

String selectDebugState(String incomingString) {
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
        String helpText = "Available commands:\n";
        helpText += "? - Output list of available commands (but you already know that)\n";
        helpText += "#[HexColor] - Set all pixels to a single color\n";
        helpText += "P# - Show a single pixel at index #\n";
        helpText += "R[start]-[end]-[hexColor] - Set a range of pixels to a hex color\n";
        helpText += "B# - Set the brightness to # (0 to 255)\n";
        helpText += "D# - Set Delay to # (in milliseconds)\n";
        helpText += "F# - Set Frequency Multiplier (1 to 1000) - higher = more manic\n";
        helpText += "N - Increment the current pattern\n";
        helpText += "M# - Set the current pattern to # (0 to 118)\n";
        helpText += "Patterns:\n";
        helpText += "M0 = SEPARATE_FLAG_PER_LETTER\n";
        helpText += "M1 = RAINBOW\n";
        helpText += "M2 = TRANS_FLAG_ANIMATED\n";
        helpText += "M3 = NONBINARY_FLAG_ANIMATED\n";
        helpText += "M4 = PAN_FLAG_ANIMATED\n";
        helpText += "M5 = BISEXUAL_FLAG_ANIMATED\n";
        helpText += "M6 = LESBIAN_FLAG_ANIMATED\n";
        helpText += "M7 = GENDERQUEER_FLAG_ANIMATED\n";
        helpText += "M8 = GENDERFLUID_FLAG_ANIMATED\n";
        helpText += "M9 = AGENDER_FLAG_ANIMATED\n";
        helpText += "M10 = INTERSEX_FLAG_ANIMATED\n";
        helpText += "M11 = POLYSEXUAL_FLAG_ANIMATED\n";
        helpText += "M12 = ASEXUAL_FLAG_ANIMATED\n";
        helpText += "M13 = AROMANTIC_FLAG_ANIMATED\n";
        helpText += "M14 = BIPOC_PRIDE_FLAG_ANIMATED\n";
        helpText += "M15 = TRANS_FLAG_STATIC\n";
        helpText += "M16 = RAINBOW_IN_EACH_LETTER\n";
        helpText += "M17 = ANIMATED_TRANS_FLAG_IN_EACH_LETTER\n";
        helpText += "M18 = STATIC_TRANS_FLAG_IN_EACH_LETTER\n";
        helpText += "--Nai1s--\n";
        return helpText;
    }
    else {
        inDebugMode = false;
        return "Unknown Command";
    }

    return "Success! Probably. You tell me.";
}
