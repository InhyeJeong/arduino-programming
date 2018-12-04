int a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(13);
  if(a==HIGH) {
    Serial.println("High");
  } else {
    Serial.println("Low");
  }
}
