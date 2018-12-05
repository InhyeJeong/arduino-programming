//  초음파 센서
int trig =2;
int echo = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  //  5v신호를 trig에 줌
  //  echo 입장에서 보낼때는 HIGH 도착하면 LOW
  digitalWrite(trig, HIGH);
  
  //   신호의 기간이 10 마이크로세컨드
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //  모듈은 trig받아서 음파를 쏘기 시작하고 받음
  //  echo핀으로 아두이노에게 보냄

  long duration = pulseIn(echo, HIGH);//  echo신호가 전달될때 사이 신호를 계산해주는 함수
  long distance = duration / 58.2 ; //  58.2라는 상수로 나눔(음속을 2로 나눈후 cm로 단위변화)
  Serial.println(distance);
  delay(100);
}
