void setup() {
  pinMode(13, OUTPUT);  //red
  pinMode(12, OUTPUT);  //yellow
  pinMode(8, OUTPUT);   //green
  

}

void loop() {
   // turn on red, turn off yellow, green
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
  delay(1000);

  // turn on yellow, turn off red, green
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

  // turn on green, turn off red, yellow
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}
