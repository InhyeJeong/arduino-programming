// 라이브러리 추가 https://github.com/Chris--A/Keypad
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;

// 버튼이 어떤 열과 행에 있는지 파악 가능
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//  신호 선
byte rowPins[ROWS] = { 9, 8, 7, 6 };  //  가로(black)
byte colPins[COLS] = { 5, 4, 3, 2 };  //  세로(white)

Keypad keypad = Keypad(makeKeymap(keys), rowPins,colPins, ROWS, COLS);
int led_pin = 13;
boolean blink = false;

//  입력받을 비밀번호 빈문자열로 초기화
String buffer = "";
//  비밀번호 1234
String mypass = "1234";
void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  //  pw 리스너
  keypad.addEventListener(Mylistener);

}

void loop() {
    char key = keypad.getKey();
//    if(key != NO_KEY) {
//    Serial.println(key);
//  }
}

void Mylistener(KeypadEvent key) {

  switch(keypad.getState()) {
    
    case PRESSED:
      if(key == '#') {//  1234# -> OPEN
        //  0 이면 같음
        //  음수면 앞에가 먼저
        //  양수면 뒤에가 먼저
       if(buffer.compareTo(mypass) == 0) {
          digitalWrite(led_pin, true);
          Serial.println("OPEN");
       }
      } else {
        //  비밀번호 쌓기
        buffer += key;
      }
      Serial.println("입력 : " + buffer);

      break;
      
    case RELEASED:
      if(key == '*') {
        digitalWrite(led_pin, false);
        Serial.println("CLEAR");
        buffer="";
      }
      break;
      
    case HOLD:
      if(key == '*') {
        Serial.println("HOLDING");
      }
  }
}
