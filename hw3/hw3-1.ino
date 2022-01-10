void setup() {
}

void loop() {
  analogWrite(3, analogRead(A1) / 4);
  delay(10);
}
