const int potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(potPin);
  Serial.println(val);
  delay(1000);
  
}
