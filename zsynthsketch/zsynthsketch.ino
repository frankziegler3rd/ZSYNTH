/*
  Frank Ziegler, Embedded Systems Final Project

  zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
  zzzzzzzzzzzzzzzzzzz ZSYNTH zzzzzzzzzzzzzzzzzzz
  zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
  
  Thanks to Professor McKee and my dad for insp-
  iring me to follow through on this project. 

  Sources used:
  - https://www.instructables.com/Connecting-a-4-x-4-Membrane-Keypad-to-an-Arduino/
  - https://www.ti.com/lit/ds/symlink/lm386.pdf
*/

#include <Keypad.h>

// Keypad variables
const byte rows = 4, cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[4] = { 9, 8, 7, 6 };
byte colPins[4] = { 5, 4, 3, 2 };

// 3rd octave
float notes[12] = { 
  130.81, 
  138.59, 
  146.83, 
  155.56, 
  164.81, 
  174.61, 
  185, 
  196, 
  207.65, 
  220, 
  233.08, 
  246.94 
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    switch (key) {
      case '1': // C
        break;
      case '2': // C#
        break;
      case '3': // D
        break;
      case 'A': // D#
        break;
      case '4': // E
        break;
      case '5': // F
        break;
      case '6': // F#
        break;
      case 'B': // G
        break;
      case '7': // G#
        break;
      case '8': // A
        break;
      case '9': // A#
        break
      case 'C': // B
        break;
      case '*': // OCTAVE UP
        updateNotes(2);
        break;
      case '0': // CHANGE WAVEFORM
        break;
      case '#': // NOT SURE YET
        break;
      case 'D': // OCTAVE DOWN
        updateNotes(1/2);
        break;
    }
  }
}

void updateNotes(float shift) {
  for (int i = 0; i < 12; i++) {
    notes[i] = notes[i] * shift;
  }
}


