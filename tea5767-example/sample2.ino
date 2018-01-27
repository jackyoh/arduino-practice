//#include <Wire.h>
#include <TEA5767Radio.h>
#include <IRremote.h>
#define SERIAL_BAUDRATE 19200
#define IR_RECEIVER_PIN 9

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

TEA5767Radio radio = TEA5767Radio();

uint8_t MAXVOLUME = 15;
void setup()
{
  Serial.begin(SERIAL_BAUDRATE);
  irrecv.enableIRIn();
  Wire.begin();
  radio.setFrequency(89.9); // pick your own frequency
  
}

void loop()
{
  if(irrecv.decode(&results)){
      //Serial.println(results.value);
      if(results.value == 33718399) {
         radio.setFrequency(89.1);
      }else if(results.value == 33702079){
         radio.setFrequency(89.5);
      }else if(results.value == 33734719){
         radio.setFrequency(89.9);
      }else if(results.value == 33693919){
         radio.setFrequency(90.3);
      }else if(results.value == 33726559){
         radio.setFrequency(92.3);
      }else if(results.value == 33710239){
         radio.setFrequency(96.7);
      }

      irrecv.resume();
  }

}
