void setupBluetooth() {
    //Serial.begin(115200);
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  //Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
}

void checkForNewBluetoothCommands() {
  if (SerialBT.available()) {
      String incomingString = SerialBT.readString();
      incomingString.trim(); 
      selectDebugState(incomingString);
  }
}

/***************************************************************************** 
 * Debug Mode Functions *
 *****************************************************************************

 #[HexColor] - Set all pixels to a single color
 * [P#] - Show a single pixel at index #
 * [Rstart-end-hexColor] - Set a range of pixels to a hex color
 * [M#] - Set the current pattern to # (0 to 13)
 * [N] - Increment the current pattern
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
    else {
        inDebugMode = false;
    }
}
