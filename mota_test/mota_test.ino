void setup() {
  pinMode(11,OUTPUT);

}

void loop() {
  digitalWrite(11,HIGH);
  delay(5000);
  digitalWrite(11, LOW);
  delay(5000);
}
