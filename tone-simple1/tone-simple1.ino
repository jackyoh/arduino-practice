const byte SP_PIN = 12;

void setup() {
 pinMode(SP_PIN, OUTPUT);
}

void loop() {
 tone(SP_PIN, 659, 150);
 delay(150);
 tone(SP_PIN, 659, 150);
 delay(150);
 tone(SP_PIN, 659, 150);
 delay(300);
 tone(SP_PIN, 523, 150);
 delay(150);
 tone(SP_PIN, 659, 150);
 delay(300);
 tone(SP_PIN, 784, 150);
 delay(300);
}
