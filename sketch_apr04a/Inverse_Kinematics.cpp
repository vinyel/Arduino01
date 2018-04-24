#include "Inverse_Kinematics.h"
#include <math.h>

//コンストラクタ
Inverse_Kinematics::Inverse_Kinematics() {
  nx = 0;
  ny = 0;
  nz = 0;
  j1 = 0;  //上腕
  j2 = 0;  //土台
  j3 = 0;  //前腕
  LOA = 15;
}

//現在指定している座標を設定※今は仮に値を置いてる角度も同様
void Inverse_Kinematics::Set_Coordinate(float x, float y, float z) {
  nx = x;
  ny = y;
  nz = z;
}

//現在指定している角度を設定
void Inverse_Kinematics::Set_Angle() {
  //j1 = 90;
  //j2 = 90;
  //j3 = 90;
}

//土台から指定した座標までの距離を取得
void Inverse_Kinematics::Set_DistanceOfCoordinate(){
  float l;
  l = Get_Pow(nx) + Get_Pow(ny) + Get_Pow(nz); //二乗を求めて
  LFB = sqrt(l);  //距離を出す
}

//上腕
float Inverse_Kinematics::Get_AngleJ1(){
  return j1;
}

//土台
float Inverse_Kinematics::Get_AngleJ2(){
  return j2;
}

//前腕
float Inverse_Kinematics::Get_AngleJ3(){
  return j3;
}

//-------以下計算

void Inverse_Kinematics::Calculate() {
  float y0, z0;  //一時変数
  float cosJ1, sinJ1;
  
  //まず角度j3を求める
  j3 = 2 * Get_ArcCos(LFB/(2 * LOA));
  an3 = 180 * (j3 / M_PI);
  //次に角度j2
  j2 = Get_ArcTan(nx/nz);
  //j2 = Get_ArcSin(nx/(LOA + LOA * Get_Cos(j3)));
  an2 = 180 * (j2 / M_PI);
  //次に角度j1

  float nxz = sqrt(Get_Pow(nx) + Get_Pow(nz));
  float n1 = Get_ArcTan(ny / nxz);
  float n2 = j3 / 2;

  j1 = n1 + n2;

  an1 = 180 * (j1 / M_PI);
  /*
  y0 = LOA * Get_Sin(j3);
  z0 = (LOA + LOA * Get_Cos(j3)) * Get_Cos(j2);

  cosJ1 = ( ny + z0 * nz / z0 ) / ( y0 + Get_Pow(z0) / y0 );
  sinJ1 = ( y0 * nz / z0 - ny ) / ( Get_Pow(y0) / z0 + z0 );
  if ( sinJ1 > 0 ) {
    j1 = Get_ArcCos(cosJ1);
    an1 = 180 * (j1 / M_PI);
  } else {
    j1 = -(Get_ArcCos(cosJ1));
    an1 = 180 * (j1 / M_PI);
  }
  */
}

//--以下、数学
//正弦を返す
float Inverse_Kinematics::Get_Sin(float x) {
  return sin(x);
}

//余弦を返す
float Inverse_Kinematics::Get_Cos(float x) {
  return cos(x);
}

//逆正弦を返す
float Inverse_Kinematics::Get_ArcSin(float x) {
  return asin(x);
}

//逆余弦を返す
float Inverse_Kinematics::Get_ArcCos(float x) {
  return acos(x);
}

float Inverse_Kinematics::Get_ArcTan(float x) {
  return atan(x);
}

//二乗を返す
float Inverse_Kinematics::Get_Pow(float x) {
  float z;
  z = x * x;
  return z;
}
