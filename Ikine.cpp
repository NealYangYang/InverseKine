#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cmath>
#include "Ikine.h"

Ikine::Ikine( double lu, double lf )
{
  Lu = lu;
  Lf = lf;
}

void Ikine::setMatrix(double inputMatrix[4][4])
{
  //输入矩阵赋值给坐标系6矩阵
  for ( int i = 0; i < 4; i++ )
    {
      for ( int j = 0; j < 4; j++ )
	T0_6[ i ][ j ] = inputMatrix[ i ][ j ];
    }
  //获取坐标系6旋转矩矩阵
  for ( int i = 0; i < 3; i++ )
    {
      for ( int j = 0; j < 3; j++ )
	R0_6[ i ][ j ] = inputMatrix[ i ][ j ];
    }
}
void Ikine::getEulerAngle()
{
  beta = atan2( -R0_6[ 2 ][ 0 ], sqrt( R0_6[0][0]*R0_6[0][0]+R0_6[1][0]*R0_6[1][0]) );
  if ( beta * 180 / M_PI == 90 )
    {
      alfa = 0;
      gama = atan2( R0_6[0][1], R0_6[1][1] );
    }else if ( beta * 180 / M_PI == -90 )
    {
      alfa = 0;
      gama = -atan2( R0_6[0][1], R0_6[1][2] );
    }else{
    alfa = atan2( R0_6[1][0] / cos(beta), R0_6[0][0] / cos(beta) );
    gama = atan2( R0_6[2][1] / cos(beta), R0_6[2][2] / cos(beta) );
  }
}

void Ikine::getQ6_0()
{
  Q6_0[0][0] = (-T0_6[0][3])*cos(alfa)*cos(beta)+(-T0_6[1][3])*sin(alfa)*cos(beta)-(-T0_6[2][3])*sin(beta);
  Q6_0[1][0] = -(-T0_6[0][3])*sin(alfa)*cos(gama)+(-T0_6[1][3])*cos(alfa)*cos(gama)+(-T0_6[0][3])*cos(alfa)*sin(beta)*sin(gama)+(-T0_6[1][3])*sin(alfa)*sin(beta)*sin(gama)+(-T0_6[2][3])*cos(beta)*sin(gama);
  Q6_0[2][0] = (-T0_6[0][3])*sin(alfa)*sin(gama)-(-T0_6[1][3])*cos(alfa)*sin(gama)+(-T0_6[0][3])*cos(alfa)*sin(beta)*cos(gama)+(-T0_6[1][3])*sin(alfa)*sin(beta)*cos(gama)+(-T0_6[2][3])*cos(beta)*cos(gama);
  Q6_0[3][0] = 1;
 
}

void Ikine::getCosTheta4()
{
  Theta4_1 = acos( (Q6_0[0][0]*Q6_0[0][0]+Q6_0[1][0]*Q6_0[1][0]+Q6_0[2][0]*Q6_0[2][0]-Lu*Lu-Lf*Lf)  / (-2*Lu*Lf) );
  Theta4_2 = -Theta4_1;
}

void Ikine::getCosTheta5()
{
  //浮点数可能在运算中导致asin()的输入值略大于1，调试完成加If
  Theta5_1_1 = asin(-Q6_0[2][0]/Lu / sin(Theta4_1));
  Theta5_2_1 = asin(-Q6_0[2][0]/Lu/sin(Theta4_2));

  if (Theta5_1_1 > 0.0 )
    {
      Theta5_1_2 = M_PI-Theta5_1_1;
    }else{
    Theta5_1_2 = -(M_PI+Theta5_1_1);
  }

  if (Theta5_2_1 > 0.0 )
    {
      Theta5_2_2 = M_PI-Theta5_2_1;
    }else{
    Theta5_2_2 = -(M_PI+Theta5_2_1);
  } 
  
}

void Ikine::getCosTheta6()
{
  double lamda1_1 = Lf - Lu*cos(Theta4_1);
  double lamda1_2 = Lu*sin(Theta4_1)*cos(Theta5_1_1);
  
  double lamda2_1 = Lf - Lu*cos(Theta4_1);
  double lamda2_2 = Lu*sin(Theta4_1)*cos(Theta5_1_2);

  double lamda3_1 = Lf - Lu*cos(Theta4_2);
  double lamda3_2 = Lu*sin(Theta4_2)*cos(Theta5_2_1);

  double lamda4_1 = Lf - Lu*cos(Theta4_2);
  double lamda4_2 = Lu*sin(Theta4_2)*cos(Theta5_2_2);

  Theta6_1_1 = atan2(lamda1_1, lamda1_2) - atan2(Q6_0[1][0],sqrt(lamda1_1*lamda1_1+lamda1_2*lamda1_2-Q6_0[1][0]*Q6_0[1][0]));
  Theta6_1_2 = atan2(lamda1_1, lamda1_2) - atan2(Q6_0[1][0],-sqrt(lamda1_1*lamda1_1+lamda1_2*lamda1_2-Q6_0[1][0]*Q6_0[1][0]));

  Theta6_2_1 = atan2(lamda2_1, lamda2_2) - atan2(Q6_0[1][0],sqrt(lamda2_1*lamda2_1+lamda2_2*lamda2_2-Q6_0[1][0]*Q6_0[1][0]));
  Theta6_2_2 = atan2(lamda2_1, lamda2_2) - atan2(Q6_0[1][0],-sqrt(lamda2_1*lamda2_1+lamda2_2*lamda2_2-Q6_0[1][0]*Q6_0[1][0]));

   Theta6_3_1 = atan2(lamda3_1, lamda3_2) - atan2(Q6_0[1][0],sqrt(lamda3_1*lamda3_1+lamda3_2*lamda3_2-Q6_0[1][0]*Q6_0[1][0]));
  Theta6_3_2 = atan2(lamda3_1, lamda3_2) - atan2(Q6_0[1][0],-sqrt(lamda3_1*lamda3_1+lamda3_2*lamda3_2-Q6_0[1][0]*Q6_0[1][0]));

  Theta6_4_1 = atan2(lamda4_1, lamda4_2) - atan2(Q6_0[1][0],sqrt(lamda4_1*lamda4_1+lamda4_2*lamda4_2-Q6_0[1][0]*Q6_0[1][0]));
  Theta6_4_2 = atan2(lamda4_1, lamda4_2) - atan2(Q6_0[1][0],-sqrt(lamda4_1*lamda4_1+lamda4_2*lamda4_2-Q6_0[1][0]*Q6_0[1][0]));
}

void Ikine::getIkine()
{
  getEulerAngle();
  getQ6_0();
  getCosTheta4();
  getCosTheta5();
  getCosTheta6();
}
