//버튼(5pin) / led2개(green :10pin / red:9pin) 아날로그가능
//초음파센서( tri:2pin / ech :3pin )
//int btn;
void setup() {
  Serial.begin(9600);
  //  ultrasonic sensor
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  //  green led
  pinMode(10, OUTPUT);
  //  red led
  pinMode(9, OUTPUT);
  //  btn
  pinMode(5, INPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH);

//  if(duration == 0) {
//    return;
//  }

  long distance = duration / 58.2 ;

  
  // led는 버튼이 눌린 상태에서만 점등됨
//  btn = digitalRead(5);

if(distance >=5 && distance <10){
  Serial.println("거리가 멀어짐");
  if(digitalRead(5) == HIGH){
    Serial.println("btn눌림");
         //초록색 점등
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
       Serial.println("거리 5이상 10 미만 : green 점등");
    } else {
      // 빨간색 점등
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
       Serial.println("거리가 멀어짐 red 점등");
    }
 
} else {
   digitalWrite(10, LOW);
    digitalWrite(9, LOW);
}
 Serial.println(distance);
delay(100);

//  if(digitalRead(5) == HIGH){
//    Serial.println("버튼이 눌렸음");
//    
//    if(distance >=5 && distance <10){
//      //초록색 점등
//      digitalWrite(10, HIGH);
//      digitalWrite(9, LOW);
//       Serial.println("거리 5이상 10 미만 : green 점등");
//    } else {
//      // 빨간색 점등
//      digitalWrite(9, HIGH);
//      digitalWrite(10, LOW);
//       Serial.println("거리가 멀어짐 red 점등");
//    }
//    
//  } else {
//    digitalWrite(10, LOW);
//    digitalWrite(9, LOW);
//  }
//  Serial.println(distance);
//  delay(100);

}
