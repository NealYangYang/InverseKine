#include <iostream>
using std::cout;
using std::endl;

class Ikine
{
 public:
  double R0_6[3][3];   //旋转矩阵R0_6
  double T0_6[4][4];   //转换矩阵T0_6
  double T0_3[4][4];
  double Sol[8][6];   //解过度矩阵
  double SolR[8][6];   //最终解矩阵

  /*四组T0_3*/
  double T0_3_1[4][4];
  double T0_3_2[4][4];
  double T0_3_3[4][4];
  double T0_3_4[4][4];
  
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
  double Theta1_1;
  double Theta2_1;
  double Theta3_1;

  double Theta1_2;
  double Theta2_2;
  double Theta3_2;


  
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
  double error;   //判断Theta4,5,6是否正确地误差值
  int flag;   //判断完成后正解的位置，0代表1.3.5.7  1代表2.4.6.8
  Ikine( double lu, double lf );   //构造函数，初始化同时提取旋x转矩阵
  void setMatrix(double inputmatrix[4][4]);
  void getEulerAngle();   //计算与旋转矩阵对应的Euler角
  void getQ6_0();    //计算前三轴交点在坐标系6中的位置矩阵
  void getCosTheta4();
  void getCosTheta5();
  void getCosTheta6();
  void checkTheta4_6();
  void fillSol();   //将解赋值到矩阵中
  void fillSolR();
  void getT0_3();
  void getT0_3test();
  void getTheta1_3();
  void getIkine();
 private:
  double matrixOfSix[ 4 ][ 4 ];   //坐标系6矩阵

};
