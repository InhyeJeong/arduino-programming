//  라이브러리 헤더 파일 추가
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  //  센서의 초기값을 보정해주는 함수.
  mpu6050.calcGyroOffsets(true);
  
  //mpu6050.setGyroOffsets(x, y, z);  // 임의값을 ()안에서 줄 수도 있음.(1.0, 2.7, 등등) > 초기값에 따라 센서값이 달라짐
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();
}
