#include "pitches.h"
const byte SP_PIN = 12;

void setup() {
 pinMode(SP_PIN, OUTPUT);
}

void loop() {
  tone(SP_PIN, NOTE_G5, 150);
  delay(150);
  tone(SP_PIN, NOTE_E5, 150);
  delay(150);
  tone(SP_PIN, NOTE_E5, 300);
  delay(300);

  tone(SP_PIN, NOTE_F5, 150);
  delay(150);
  tone(SP_PIN, NOTE_D5, 150);
  delay(150);
  tone(SP_PIN, NOTE_D5, 300);
  delay(300);

  tone(SP_PIN, NOTE_C5, 150);
  delay(150);
  tone(SP_PIN, NOTE_D5, 150);
  delay(150);
  tone(SP_PIN, NOTE_E5, 300);
  delay(150);
  tone(SP_PIN, NOTE_F5, 300);
  delay(150);

  
  tone(SP_PIN, NOTE_G5, 300);
  delay(150);
  tone(SP_PIN, NOTE_G5, 300);
  delay(150);
  tone(SP_PIN, NOTE_G5, 300);
  delay(150);

  
}
