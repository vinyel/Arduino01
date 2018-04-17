#include <Servo.h>
//http://denshi.blog.jp/arduino/serial_servo_motor
Servo myservo1;   //0～90  上腕
Servo myservo2;   //0～90 前腕
Servo myservo3;   //0～180  土台の回転角度

// グローバル変数の宣言
char input[4];  // 文字列格納用
char inputServo;

int i = 0;      // 文字数のカウンタ

int val = 90;    // 受信した数値
int deg = 90;    // サーボの角度

bool isServo = false;
int ss = 1;

void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
    // シリアルポートを9600 bps[ビット/秒]で初期化 
  Serial.begin(9600);
  Serial.println("input deg after input 1~3\n");
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
}

void selectServo() {
  if ( inputServo == '1' || inputServo == '2' || inputServo == '3' ) {
    Serial.println("Accepted:");
    Serial.println(inputServo);
    ss = ctoi(inputServo);
    isServo = true;
  } else {
    Serial.println("Not Accepted");
    isServo = false;
  }
}

void loop() {
  
  if ( Serial.available() && !isServo ) {
    inputServo = Serial.read();
    selectServo();
  }
  
  if ( Serial.available() && isServo ) {
    input[i] = Serial.read();
    //文字数が3以上か末尾文字がある場合の処理
    if ( i > 2 || input[i] == '.' ) {
      input[i] = '\0'; //末尾に終端文字の挿入
      val = atoi(input); //文字列を数値に変換
      Serial.write(input);  //文字列を送信
      Serial.write("\n");
      i = 0;  //カウンタの初期化
      isServo = false;
    }
    else { i++; }
      deg = val;
  switch(ss) {
    case 1:
      myservo1.write(deg);
      break;
    case 2:
      myservo2.write(deg);
      break;
    case 3:
      myservo3.write(deg);
      break;
    default:
      break;
  }
  }
}

int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}
