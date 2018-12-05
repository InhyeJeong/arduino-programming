void setup() {}
// 조도센서
// A0으로 조도센서의 값이 전달됨
// 값을 변수에 저장함 (0~1023)
//-----------------------------------
//센서 값 0~1023
//아두이노 아날로그 출력 값 Pwm 0~255
//> 범위가 맞지 않음
//> 최솟값과 최댓값을 비율로 따져서 matching >함수 map


void loop() {
  Serial.println("루프 시작됨");
  int light = analogRead(A0);
  // 어두우면 led를 밝혀야하므로 매개변수 3~4번째는 순서가 바뀌어야 함.
  int ledLight = map(light, 0, 500, 255, 0);
  analogWrite(9, ledLight);

  //  스피커 추가
  int hertz = map(light, 0, 500, 31, 4978);
  tone(8, hertz, 100);
  delay(100);
  noTone(8);
  delay(200);
}
