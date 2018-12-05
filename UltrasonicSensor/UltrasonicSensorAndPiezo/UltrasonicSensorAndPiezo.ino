// 초음파 센서 + 피에조 센서
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

} 

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH);

  if(duration == 0) {
    return;
  }

  long distance = duration / 58.2 ;

  tone(8, 1000, 20);
  delay(20);
  noTone(8);

  delay(2*distance);

  
}
