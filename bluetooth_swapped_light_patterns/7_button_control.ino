
#define BUTTON_PIN 19 // GPIO21 pin connected to button

// Variables will change:
int lastState = HIGH; // the previous state from the input pin
int currentState;     // the current reading from the input pin

void initializeButton() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void checkButtonState() {
    // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if(lastState == LOW && currentState == HIGH) {
    incrementCurrentPattern(); // button was pressed, increment pattern
    inDebugMode = false; // exit debug mode if it was active
  }

  // save the last state
  lastState = currentState;
}