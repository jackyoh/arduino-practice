byte LEDs[10][7] = {
  {1, 2, 3, 4, 5, 6, 8},
  {4, 5, 8, 8, 8, 8, 8},
  {0, 2, 3, 5, 6, 8, 8},
  {0, 3, 4, 5, 6, 8, 8},
  {0, 1, 4, 5, 8, 8, 8},
  {0, 1, 3, 4, 6, 8, 8},
  {0, 1, 2, 3, 4, 6, 8},
  {1, 4, 5, 6, 8, 8, 8},
  {0, 1, 2, 3, 4, 5, 6},
  {0, 1, 3, 4, 5, 6, 8}
};

byte index = 0;
void setup() {
  for(byte i = 0 ; i <=6 ; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
 for(byte i = 0 ; i <= 6 ; i++){
  digitalWrite(LEDs[index][i], HIGH);
 }
 index++;
 if(index == 10){
   index =0;
 }
 delay(1000);
 reset();
}

void reset(){
  for(byte i = 0 ; i <= 6 ; i++){
     digitalWrite(i, LOW);
  }
}
