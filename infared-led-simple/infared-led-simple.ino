#include <IRremote.h>
#include "pitches.h"
const byte SP_PIN = 7;

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(SP_PIN, OUTPUT);
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value);
    if(results.value == 2105400865){
      speak1();
    }else if(results.value == 2105360065){
      speak2();
    }
    irrecv.resume();
  }

}

void speak1(){
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

void speak2(){
  tone(SP_PIN, NOTE_G5, 150);
  delay(150);
  tone(SP_PIN, NOTE_G5, 150);
  delay(150);
  tone(SP_PIN, NOTE_G5, 300);
  delay(150);
  tone(SP_PIN, NOTE_G5, 300);
  delay(150);
  
}

