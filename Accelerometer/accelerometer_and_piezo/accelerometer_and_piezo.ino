#include <MPU6050_tockn.h>
#include <Wire.h>

//  객체 생성
MPU6050 mpu6050(Wire);

int y_angle = 0;    //  값 저장
int piezo_pin = 8;  // 핀번호

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  //  값이 true이면 보정과정을 거침
  mpu6050.calcGyroOffsets(true);

  //  직접 값을 줄 수도 있음
//  mpu6050.setGyroOffsets(-0.81, 2.02, -2.17);
}

void loop() {
  //  xyz축 출력
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();

  y_angle = mpu6050.getAngleY();


//  y축으로 45도 기울어진 경우 경고음 
  if(y_angle > 0) { //  양수인 경우 : 시계방향으로 기울었을 때
    if(y_angle > 45) {
      tone(piezo_pin, 440, 250);
    } 
  } else {
    if(y_angle < -45) { //  음수인 경우 : 반시계 방향으로 기울었을 때
      tone(piezo_pin, 440, 250);
    }
  }

  //  abs : 절대값 취하는 함수
  // +_이든 간에 소리를 나게 할 때
/*
  if(abs(y_angle) > 45) {
    tone(piezo_pin, 440, 250);
  }
*/
  
  delay(500);
}
