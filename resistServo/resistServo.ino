#include<Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
    Serial.println(val);
  
  
  int rad = map(val, 0, 1023, 0, 160);
  myservo.write(rad);
  delay(150);
}
