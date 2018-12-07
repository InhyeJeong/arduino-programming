//버튼(5pin) / led2개(green :10pin / red:9pin) 아날로그가능
//초음파센서( tri:2pin / ech :3pin )

int btn = 13;
int red = 8;
int green = 9;
int trig = 2;
int echo = 3;

void setup() {
  Serial.begin(9600);
  //  ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //  green led
  pinMode(green, OUTPUT);
  //  red led
  pinMode(red, OUTPUT);
  //  btn
  pinMode(btn, INPUT);

}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);  // 10 밀리세컨드(0.01초)동안 trigger핀을 high로 하면 초음파가 나옴
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);

  long distance = duration / 58.2 ;

  
  // led는 버튼이 눌린 상태에서만 점등됨
  if(digitalRead(btn) == HIGH){
    Serial.println("btn pushed");
    
    if(distance >=5 && distance <10){
      //초록색 점등
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
       Serial.println("거리 5이상 10 미만 : green 점등");
    } else {
      // 빨간색 점등
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
       Serial.println("거리가 멀어짐 red 점등");
    }
    
  } else {
    Serial.println("btn unpushed");
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
  }
  Serial.println("distance : ");
  Serial.println(distance);
  Serial.println("------------------------------------------------------");
  delay(100);

}
