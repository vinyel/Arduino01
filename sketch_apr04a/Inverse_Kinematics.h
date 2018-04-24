class Inverse_Kinematics {
  public:
    float nx, ny, nz;
    float j1, j2, j3;
    float an1, an2, an3;
   
    float LFB;  //土台からの距離
    float LOA; //Length of Arm
    Inverse_Kinematics(); //コンストラクタ
    void Set_Coordinate(float x, float y, float z);
    void Set_Angle();
    void Set_DistanceOfCoordinate();
    float Get_AngleJ1();
    float Get_AngleJ2();
    float Get_AngleJ3();
    void Calculate();
    float Get_Sin(float x);
    float Get_Cos(float x);
    float Get_ArcSin(float x);
    float Get_ArcCos(float x);
    float Get_ArcTan(float x);
    float Get_Pow(float x);
};

