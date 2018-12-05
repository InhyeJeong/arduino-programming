int timer = 1000;

void setup() {
  // use a for loop to initialize each pin as an output:
  for(int i = 2; i<12; i ++) {
      pinMode(i, OUTPUT); 
  }
 }

//  r > y > g 밝아지다가 어두워지는 형태로 코드
//  아날로그로 출력?
void loop() {

  
 //  밝아짐
  for(int i=11; i>5; i--){
    //  on
     digitalWrite(i, HIGH);
     delay(timer);
 }
// 어두워짐
  for (int i = 6; i < 12; i++) { 
    //  off:
    digitalWrite(i, LOW);
    delay(timer);
  }

  
 

}
