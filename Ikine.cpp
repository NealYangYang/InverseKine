#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cmath>
#include "Ikine.h"
#include "Matrix.h"

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
  if ( fabs(beta * 180 / M_PI - 90) < 0.001 )
    {
      alfa = 0;
      gama = atan2( R0_6[0][1], R0_6[1][1] );
    }else if (fabs( beta * 180 / M_PI +90) < 0.001 )
    {
      alfa = 0;
      gama = -atan2( R0_6[0][1], R0_6[1][1] );
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

void Ikine::checkTheta4_6()
{
  error = 0.01; 

  if (fabs( cos(Sol[0][5])*Lu*sin(Sol[0][3])*cos(Sol[0][4])+sin(Sol[0][5])*(Lf-Lu*cos(Sol[0][3])) - Q6_0[0][0] ) < error)
    {
      flag = 0;
    }else{
    flag = 1;
  }
}

void Ikine::fillSol()
{
  for ( int i = 0; i < 4; i ++ )
    {
      Sol[i][3] = Theta4_1;
    }
  for ( int i = 4; i < 8; i++ )
    {
      Sol[i][3] = Theta4_2;
    }

  Sol[0][4] = Theta5_1_1;
  Sol[1][4] = Theta5_1_1;
  Sol[2][4] = Theta5_1_2;
  Sol[3][4] = Theta5_1_2;
  Sol[4][4] = Theta5_2_1;
  Sol[5][4] = Theta5_2_1;
  Sol[6][4] = Theta5_2_2;
  Sol[7][4] = Theta5_2_2;

  Sol[0][5] = Theta6_1_1;
  Sol[1][5] = Theta6_1_2;
  Sol[2][5] = Theta6_2_1;
  Sol[3][5] = Theta6_2_2;
  Sol[4][5] = Theta6_3_1;
  Sol[5][5] = Theta6_3_2;
  Sol[6][5] = Theta6_4_1;
  Sol[7][5] = Theta6_4_2;
  
}

void Ikine::fillSolR()
{
  
  if ( flag == 0 )   //正解是1.3.5.7
    {
      for ( int i = 0; i < 8; i=i+2 )
	{
	  for ( int j = 3; j < 6; j++)
	    SolR[i/2][j] = Sol[i][j];
	}
    }else{   //正解是2.4.6.8
    for ( int i = 1; i < 9; i=i+2 )
      {
	for ( int j = 3; j < 6; j++)
	  SolR[i/2][j] = Sol[i][j];
      }
  }

  for ( int i = 0; i < 4; i++)
    {
      for ( int j = 3; j < 6; j++ )
	{
	  SolR[i+4][j] = SolR[i][j];
	}
    }
}  

void Ikine::getT0_3()
{
  int i = 2;
  int m = 4;
  int n = 4;
  double T6_3[4][4] =
    {
      {cos(SolR[i][3])*cos(SolR[i][4])*cos(SolR[i][5])+sin(SolR[i][3])*sin(SolR[i][5]), -sin(SolR[i][4])*cos(SolR[i][5]), -sin(SolR[i][3])*cos(SolR[i][4])*cos(SolR[i][5])+cos(SolR[i][3])*sin(SolR[i][5]), Lf*sin(SolR[i][5])},
      {-cos(SolR[i][3])*cos(SolR[i][4])*sin(SolR[i][5])+sin(SolR[i][3])*cos(SolR[i][5]), sin(SolR[i][4])*sin(SolR[i][5]), sin(SolR[i][3])*cos(SolR[i][4])*sin(SolR[i][5])+cos(SolR[i][3])*cos(SolR[i][5]), Lf*cos(SolR[i][5])},
      {-cos(SolR[i][3])*sin(SolR[i][4]), -cos(SolR[i][4]), sin(SolR[i][3])*sin(SolR[i][4]), 0},
      {0,0,0,1}
    };
  
  //输出测试
  cout << "T6_3 :" << endl;
    for (int i = 0; i < 4; i++ )
    {
      for (int j = 0; j < 4; j++ )
	{
	  cout << setw(10) << T6_3[i][j];
	  if (j == 3)
	    {
	      cout << endl;
	    }
	}
    }
  
  
   Matrix a(4,4);
   for(int i=0;i<m;i++)//动态数组赋值
     for(int j=0;j<n;j++)
       a.data[i][j]=T0_6[i][j];
         
   Matrix b(4,4);
   for(int i=0;i<m;i++)//动态数组赋值
     for(int j=0;j<n;j++)
       b.data[i][j]=T6_3[i][j];

   Matrix c = a * b;
   for(int i=0;i<m;i++)//动态数组赋值
     for(int j=0;j<n;j++)
       T0_3[i][j]=c.data[i][j];

     //输出测试
  cout << "T0_3 :" << endl;
    for (int i = 0; i < 4; i++ )
    {
      for (int j = 0; j < 4; j++ )
	{
	  cout << setw(10) << T0_3[i][j];
	  if (j == 3)
	    {
	      cout << endl;
	    }
	}
    }

}

void Ikine::getT0_3test()
{

  double pi = 180;
  double a1 = 125.0 /pi * M_PI;
  double a2 = -15.0/pi* M_PI ;
  double a3 = 39.0/pi* M_PI ;
  double T0_3test[4][4] =
    {
      {cos(a1)*cos(a2)*cos(a3)-sin(a1)*sin(a3), -cos(a1)*cos(a2)*sin(a3)-sin(a1)*cos(a3), cos(a1)*sin(a2), Lu*cos(a1)*sin(a2)},
      {sin(a1)*cos(a2)*cos(a3)+cos(a1)*sin(a3), -sin(a1)*cos(a2)*sin(a3)+cos(a1)*cos(a3), sin(a1)*sin(a2), Lu*sin(a1)*sin(a2)},
      {-sin(a2)*cos(a3), sin(a2)*sin(a3), cos(a2), Lu*cos(a2)},
    {0, 0, 0, 1}
    };

   //输出测试
  cout << "T0_3test :" << endl;
    for (int i = 0; i < 4; i++ )
    {
      for (int j = 0; j < 4; j++ )
	{
	  cout << setw(10) << T0_3test[i][j];
	  if (j == 3)
	    {
	      cout << endl;
	    }
	}
    }
}

void Ikine::getTheta1_3()
{
  double a;
  double b;
  double c;
  double a1,b1,c1;
b = atan2( -T0_3[ 2 ][ 0 ], sqrt( T0_3[0][0]*T0_3[0][0]+T0_3[1][0]*T0_3[1][0]) );

 if (fabs(b * 180 / M_PI - 90) < 0.01 )
    {
      a = 0;
      c = atan2( T0_3[0][1], T0_3[1][1] );
    }else if (fabs(b * 180 / M_PI  + 90) < 0.01 )
    {
      a = 0;
      c = -atan2( T0_3[0][1], T0_3[1][1] );
    }else{
    a = atan2( T0_3[1][0] / cos(b), T0_3[0][0] / cos(b) );
    c = atan2( T0_3[2][1] / cos(b), T0_3[2][2] / cos(b) );
  }

 b1 = atan2( -T0_3[ 2 ][ 0 ], -sqrt( T0_3[0][0]*T0_3[0][0]+T0_3[1][0]*T0_3[1][0]) );

 if (fabs(b1 * 180 / M_PI - 90) < 0.01 )
    {
      a1 = 0;
      c1 = atan2( T0_3[0][1], T0_3[1][1] );
    }else if (fabs(b1 * 180 / M_PI  + 90) < 0.01 )
    {
      a1 = 0;
      c1 = -atan2( T0_3[0][1], T0_3[1][1] );
    }else{
    a1 = atan2( T0_3[1][0] / cos(b1), T0_3[0][0] / cos(b1) );
    c1 = atan2( T0_3[2][1] / cos(b1), T0_3[2][2] / cos(b1) );
  }
  
  Theta1_1 = a1;
  Theta2_1 = b1;
  Theta3_1 = c1;

  Theta1_2 = a;
  Theta2_2 = b;
  Theta3_2 = c;

  
}

void Ikine::getIkine()
{
  getEulerAngle();
  getQ6_0();
  getCosTheta4();
  getCosTheta5();
  getCosTheta6();
  fillSol();
  checkTheta4_6();
  fillSolR();
  getT0_3();
  getTheta1_3();
  getT0_3test();
}
