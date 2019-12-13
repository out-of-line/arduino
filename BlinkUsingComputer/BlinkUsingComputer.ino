#define LED 13

void setup() {
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
if (Serial.available()) {
char c = Serial.read();
if (c == 'H') {
digitalWrite(LED, HIGH);
//Serial.println("LED switched ON!");
}
else if (c == 'L') {
digitalWrite(LED, LOW);
//Serial.println("LED switched OFF!");
}
}
}
