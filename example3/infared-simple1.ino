#include <IRremote.h>
int RECV_PIN = 2;
int LED_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value);
    if(results.value == 33718399){
      digitalWrite(LED_PIN, HIGH);
    }else if(results.value == 33702079){
      digitalWrite(LED_PIN, LOW);
    }   
    irrecv.resume();
  }
}
