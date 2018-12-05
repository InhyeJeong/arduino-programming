// 시리얼 통신
void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char c = Serial.read();
    //  시리얼에서 a라고 입력하면 A라고 출력
    if(c == 'a') {
        Serial.println("A");
    }
  }
}
