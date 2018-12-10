#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // 아두이노의 2번 TX, 3번 RX

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);  //  블루투스와 아두이노가 통신하는 시리얼

  //  핀 설정
  pinMode(7, OUTPUT); // LED OUTPUT
  pinMode(8, OUTPUT); // LED OUTPUT
}

void loop()
{
  char val = bluetooth.read();

  if (bluetooth.available())
  {
    Serial.write(bluetooth.read());
  }

  if(val == 'a')
  {
    digitalWrite(7,HIGH);
  }

  if(val == 'b')
  {
    digitalWrite(8, HIGH);
  }

  else if(val == 'c')
  {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  
}
