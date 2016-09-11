#include "pitches.h"
const byte SP_PIN = 12;

void setup() {
 pinMode(SP_PIN, OUTPUT);
}

void loop() {
 tone(SP_PIN, NOTE_E5, 150);
 delay(150);
 tone(SP_PIN, NOTE_E5, 150);
 delay(150);
 tone(SP_PIN, NOTE_E5, 150);
 delay(300);
 tone(SP_PIN, NOTE_C5, 150);
 delay(150);
 tone(SP_PIN, NOTE_E5, 150);
 delay(300);
 tone(SP_PIN, NOTE_G5, 150);
 delay(300);
}
