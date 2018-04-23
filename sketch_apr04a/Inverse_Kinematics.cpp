#include "Inverse_Kinematics.h"
#include <cmath>

//コンストラクタ
Inverse_Kinematics::Inverse_Kinematics() {
  nx = 0f;
  ny = 0f;
  nz = 0f;
  j1 = 0f;  //上腕
  j2 = 0f;  //土台
  j3 = 0f;  //前腕
  LOA = 15f;
}

//現在指定している座標を設定※今は仮に値を置いてる角度も同様
void Inverse_Kinematics::Set_Coordinate(float x, float y, float z) {
  nx = 10f;
  ny = 10f;
  nz = 5f;
}

//現在指定している角度を設定
void Inverse_Kinematics::Set_Angle() {
  j1 = 90f;
  j2 = 90f;
  j3 = 90f;
}

//土台から指定した座標までの距離を取得
void Inverse_Kinematics::Get_DistanceOfCoordinate(){
  float l;
  l = Get_Pow(nx) + Get_Pow(ny) + Get_Pow(nz); //二乗を求めて
  LFB = sqrt(l);  //距離を出す
}

float Inverse_Kinematics::Get_AngleJ1(){
  return j1;
}

float Inverse_Kinematics::Get_AngleJ2(){
  return j2;
}

float Inverse_Kinematics::Get_AngleJ3(){
  return j3;
}

//-------以下計算

void Inverse_Kinematics::Calculation() {
  float y0, z0;  //一時変数
  float cosJ1, sinJ1;
  
  //まず角度j3を求める
  j3 = 2 * Get_ArcSin(LFB/2LOA);
  //次に角度j2
  j2 = Get_ArcSin(nx/(LOA + LOA * Get_Cos(j3)));
  //次に角度j1
  y0 = LOA * Get_Sin(j3);
  z0 = (LOA + LOA * Get_Cos(j3)) * Get_Cos(j2);

  cosJ1 = ( ny + z0 * nz / z0 ) / ( y0 + Get_Pow(z0) / y0 )
  sinJ1 = ( y0 * nz / z0 - ny ) / ( Get_Pow(y0) / z0 + z0 );
  if ( sinJ1 > 0f ) {
    j1 = Get_ArcCos(cosJ1);
  } else {
    j1 = -(Get_ArcCos(cosJ1))
  }
}

//--以下、数学
//正弦を返す
float Inverse_Kinematics::Get_Sin(float x) {
  return std::sin(x);
}

//余弦を返す
float Inverse_Kinematics::Get_Cos(float x) {
  return std::cos(x);
}

//逆正弦を返す
float Inverse_Kinematics::Get_ArcSin(float x) {
  return std::asin(x);
}

//逆余弦を返す
float Inverse_Kinematics::Get_ArcCos(float x) {
  return std::acos(x);
}

//二乗を返す
float Inverse_Kinematics::Get_Pow(float x) {
  float z;
  z = x * x;
  return z;
}
