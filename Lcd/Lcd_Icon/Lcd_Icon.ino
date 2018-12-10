#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x3F, 16, 2); 

void setup()
{
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.print("(^o^)    @ (^_-)"); 
  delay(1000);
  lcd.home();
  lcd.clear();
  
  lcd.print("(-_^) @    (^o^)"); 
  delay(1000);
  lcd.home();
  lcd.clear();
  
}
