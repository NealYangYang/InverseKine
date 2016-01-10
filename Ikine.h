#include <iostream>
using std::cout;
using std::endl;

class Ikine
{
 public:
  double R0_6[3][3];   //旋转矩阵R0_6
  double T0_6[4][4];   //转换矩阵T0_6
  double Sol[16][6];
  
  /***机械臂参数***/
  double Lu;
  double Lf;
  
  /***Euler角 ***/
  double alfa;
  double beta;
  double gama;

  /***前三轴交点在坐标系6中的位置矩阵***/
  double Q6_0[4][1];

  /***目标角度***/
  double Theta1;
  double Theta2;
  double Theta3;
  
  double Theta4_1;
  double Theta4_2;
  
  double Theta5_1_1;
  double Theta5_1_2;
  double Theta5_2_1;
  double Theta5_2_2;
  
  double Theta6_1_1;
  double Theta6_1_2;
  double Theta6_2_1;
  double Theta6_2_2;
  double Theta6_3_1;
  double Theta6_3_2;
  double Theta6_4_1;
  double Theta6_4_2;
  double error;
  Ikine( double lu, double lf );   //构造函数，初始化同时提取旋x转矩阵
  void setMatrix(double inputmatrix[4][4]);
  void getEulerAngle();   //计算与旋转矩阵对应的Euler角
  void getQ6_0();    //计算前三轴交点在坐标系6中的位置矩阵
  void getCosTheta4();
  void getCosTheta5();
  void getCosTheta6();
  void checkTheta4_6();
  void getT0_3();
  void getIkine();
 private:
  double matrixOfSix[ 4 ][ 4 ];   //坐标系6矩阵

};
