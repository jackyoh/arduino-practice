byte LEDa = 6;
byte LEDb = 5;
byte LEDc = 4;
byte LEDd = 3;
byte LEDe = 2;
byte LEDf = 1;
byte LEDg = 0;
byte index = 9;

void setup() {
  pinMode(LEDa, OUTPUT);
  pinMode(LEDb, OUTPUT);
  pinMode(LEDc, OUTPUT);
  pinMode(LEDd, OUTPUT);
  pinMode(LEDe, OUTPUT);
  pinMode(LEDf, OUTPUT);
  pinMode(LEDg, OUTPUT);
}

void loop() {
  showDigit(index);
 

  if(index == 0){
    index = 10;
  }
   index--;
  delay(1000);

}

void showDigit(int d){
 if(d == 0){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, HIGH);
    digitalWrite(LEDf, HIGH);
    digitalWrite(LEDg, LOW);
 }else if(d == 1){
    digitalWrite(LEDa, LOW);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, LOW);
    digitalWrite(LEDe, LOW);
    digitalWrite(LEDf, LOW);
    digitalWrite(LEDg, LOW);
 }else if(d == 2){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, LOW); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, HIGH);
    digitalWrite(LEDf, LOW);
    digitalWrite(LEDg, HIGH);
 }else if(d == 3){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, LOW);
    digitalWrite(LEDf, LOW);
    digitalWrite(LEDg, HIGH);
 }else if(d == 4){
    digitalWrite(LEDa, LOW);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, LOW);
    digitalWrite(LEDe, LOW);
    digitalWrite(LEDf, HIGH);
    digitalWrite(LEDg, HIGH);
 }else if(d == 5){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, LOW);
    digitalWrite(LEDf, HIGH);
    digitalWrite(LEDg, HIGH);
 }else if(d == 6){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, HIGH);
    digitalWrite(LEDf, HIGH);
    digitalWrite(LEDg, HIGH);
 }else if(d == 7){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, LOW);
    digitalWrite(LEDe, LOW);
    digitalWrite(LEDf, LOW);
    digitalWrite(LEDg, LOW);
 }else if(d == 8) {
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, HIGH);
    digitalWrite(LEDf, HIGH);
    digitalWrite(LEDg, HIGH);
 }else if(d == 9){
    digitalWrite(LEDa, HIGH);
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDc, HIGH); 
    digitalWrite(LEDd, HIGH);
    digitalWrite(LEDe, LOW);
    digitalWrite(LEDf, HIGH);
    digitalWrite(LEDg, HIGH);
 }  
}

