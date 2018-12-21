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

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  keypad.addEventListener(Mylistener);
}

void loop() {
  char key = keypad.getKey();

  if(key != NO_KEY) {
    Serial.println(key);
  }
}

void Mylistener(KeypadEvent key) {
  switch(keypad.getState()) {
    case PRESSED:
      if(key == '#') {
        digitalWrite(led_pin, true);
        Serial.println("PRESSED");
      }
      break;
    case RELEASED:
      if(key == '*') {
        digitalWrite(led_pin, false);
        Serial.println("RELEASED"); 
      }
      break;
    case HOLD:
      if(key == '*') {
        Serial.println("HOLDING");
      }
  }
}
