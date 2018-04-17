#include <Servo.h>
//http://denshi.blog.jp/arduino/serial_servo_motor
Servo myservo1;   //0～90  前腕
Servo myservo2;   //0～180 土台の回転角度
Servo myservo3;   //0～90  上腕

// グローバル変数の宣言
char input[4];  // 文字列格納用
int i = 0;      // 文字数のカウンタ
int val = 90;    // 受信した数値
int deg = 90;    // サーボの角度

void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
    // シリアルポートを9600 bps[ビット/秒]で初期化 
  Serial.begin(9600);
}

int serialNumVal() {
  //データを受信した場合
  if ( Serial.available() ) {
    input[i] = Serial.read();
    //文字数が3以上か末尾文字がある場合の処理
    if ( i > 2 || input[i] == '.' ) {
      input[i] = '\0'; //末尾に終端文字の挿入
      val = atoi(input); //文字列を数値に変換
      Serial.write(input);  //文字列を送信
      Serial.write("\n");
      i = 0;  //カウンタの初期化
    }
    else { i++; }
  }
  return val;
}

void loop() {
  deg = serialNumVal();
  myservo1.write(deg);
  myservo2.write(deg);
  myservo3.write(deg);
}
