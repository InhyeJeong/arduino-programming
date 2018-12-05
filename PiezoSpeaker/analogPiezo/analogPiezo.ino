int pzo = 6;  //  아날로그 6번 핀 : 디지털 핀이지만 아날로그처럼 출력가능
int dly = 250;

void setup() {
  pinMode(pzo, OUTPUT);
}

void loop() {
  analogWrite(pzo, 64);
  delay(dly);
   analogWrite(pzo, 128);
  delay(dly);
    analogWrite(pzo, 255);
  delay(dly);

}
