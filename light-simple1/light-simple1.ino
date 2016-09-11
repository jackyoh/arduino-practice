const byte LED = 8;
const byte Cds = A0;

void setup() {
  Serial.begin(9600);
 pinMode(LED, OUTPUT);
 }

void loop() {
 int val;
 val = analogRead(A0);
 Serial.println(val);
if(val >= 900){
   digitalWrite(LED, HIGH);
   
}else{
  digitalWrite(LED, LOW);
}
 
}
