#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //  lcd

SoftwareSerial bluetooth(2, 3); // 아두이노의 2번 TX, 3번 RX

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);  //  블루투스와 아두이노가 통신하는 시리얼
  //  lcd on
  lcd.begin();
  lcd.backlight();
  lcd.home();
  lcd.print("@_@");
  lcd.noBlink();
}

void loop() {

  char val = bluetooth.read();

   if (bluetooth.available())
  {
    Serial.write(bluetooth.read());
  }
 
  
  //  smartphone에서 움직이면 캐릭터 움직임
  //  r 입력시 오른쪽으로
  if(val == 'r') {
    lcd.scrollDisplayRight();   
  }
  //  l 입력시 왼쪽으로
  if(val == 'l') {
    lcd.scrollDisplayLeft();
  }

}
