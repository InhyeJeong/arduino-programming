#include <dht11.h>
//  온습도 센서
int DHT11PIN = A0;            //Signal 이 연결된 아두이노의 핀번호
 
dht11 DHT11;
  
void setup()
{
  Serial.begin(9600);  //시리얼 통신속도 설정
}
  
void loop()
{
  int chk = DHT11.read(DHT11PIN);
  //  온도
  Serial.print("Temp: ");
  float temper = (float)DHT11.temperature;
  
  Serial.print(temper);
  Serial.print(" C ");
  
  //  습도
  Serial.print("/ RelF: ");

  float humidity =(float)DHT11.humidity; 
  Serial.print(humidity);
  Serial.print(" %");

  // 불쾌지수
  int AngryLevel = 9/5*temper - 0.55 *(1 - humidity/100) * (9/5*temper-26) + 32;
  Serial.print(" 불쾌지수 : ");
  Serial.print(AngryLevel);
 
  Serial.println();
   
  delay(2000);
}
