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

const byte rows = 4, cols = 4;

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[4] = { 9, 8, 7, 6 };
byte colPins[4] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  Serial.begin(9600);

}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
  }

}
