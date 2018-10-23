void setup() {
  pinMode(5,OUTPUT);

}

void loop() {
  int i;

  for(i = 0;i < 255; i++){
    analogWrite(5,i);
    delay(100);
  }

  analogWrite(5,LOW);
  delay(100);


}
