#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
int y_angle = 0;
int piezo_pin = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
//  mpu6050.setGyroOffsets(-0.81, 2.02, -2.17);
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

  y_angle = mpu6050.getAngleY();

//  y축으로 45도 기울어진 경우 경고음 

  if(y_angle > 0) { 
    if(y_angle > 45) {
      tone(piezo_pin, 440, 250);
    } 
  } else {
    if(y_angle < -45) {
      tone(piezo_pin, 440, 250);
    }
  }
/*
  if(abs(y_angle) > 45) {
    tone(piezo_pin, 440, 250);
  }
*/
  
  delay(500);
}
