void setup() {// 초기설정
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);// 13번 핀은 output 내장 led
}

void loop() { // 반복
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);// high 꺼짐
  delay(1000);
  digitalWrite(13, LOW);// low 꺼짐
  delay(1000);
}
