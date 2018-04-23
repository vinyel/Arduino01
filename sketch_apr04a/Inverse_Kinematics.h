class Inverse_Kinematics {
  public:
    float nx, ny, nz;
    float j1, j2, j3;
    float LFB;  //土台からの距離
    float LOA; //Length of Arm
    Inverse_Kinematics(); //コンストラクタ
    Set_Coordinate(float x, float y, float z);
    Set_Angle();
    Get_DistanceOfCoordinate();
    Get_AngleJ1();
    Get_AngleJ2();
    Get_AngleJ3();
    Calculation();
    Get_Sin(float x);
    Get_Cos(float x);
    Get_ArcSin(float x);
    Get_ArcCos(float x);
    Get_Pow(float x);
}
