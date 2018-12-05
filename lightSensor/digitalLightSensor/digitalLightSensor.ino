//  디지털로도 받을 수 있음

int led_pin=13;
void setup() {
  pinMode(led_pin, OUTPUT);
 }

void loop() {

  int light = analogRead(A0);
  // 어두우면 led를 밝혀야하므로 매개변수 3~4번째는 순서가 바뀌어야 함.
  int ledLight = map(light, 0, 500, 255, 0);

  if(light<=500){
    digitalWrite(led_pin, HIGH);
  } else {
     digitalWrite(led_pin, LOW);
  }
}
