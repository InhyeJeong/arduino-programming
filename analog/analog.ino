
void setup() {}

void loop() {
  analogWrite(9,0);
  delay(500);
  // 9번 핀의 전압을 V로 설정합니다.
  analogWrite(9, 63);
  delay(500);
  // 9번 핀의 전압을 2.5V로 설정합니다.
  analogWrite(9, 127);
  delay(500);
  // 9번 핀의 전압을 5V로 설정합니다.
  analogWrite(9, 255);
  delay(500);
  // 9번 핀의 전압을 2.5V로 설정합니다.
  analogWrite(9, 127);
  delay(500);
  // 9번 핀의 전압을 V로 설정합니다.
  analogWrite(9, 63);
  delay(500);
  
  //  for문으로 바꿔보기 점점 밝아짐
  for(int i=0; i<=255; i=i+10){
    analogWrite(9, i);
    delay(100);
  }
  //  점점 어두워짐
 for(int i=255; i>=0; i=i-10){
    analogWrite(9, i);
    delay(100);
  }
  
}
