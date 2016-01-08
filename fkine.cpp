#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cmath>

void fkine( double a1, double a2, double a3, double a4, double a5, double a6);

double o1 = 56.3;
double o2 = 123.9;
double o3 =-23.7;
double o4 = 134.5;
double o5 =-120.4;
double o6 =-23.8;

double pi = 180;

double a1 = o1/pi*M_PI;
double a2 = o2/pi*M_PI;
double a3 = o3/pi*M_PI;
double a4 = o4/pi*M_PI;
double a5 = o5/pi*M_PI;
double a6 = o6/pi*M_PI;

double Lu = 50;
double Lf = 70;
double T[4][4];

int main()
{
  fkine(a1, a2, a3, a4, a5, a6);
  cout << T[0][0] << setw(15) << T[0][1] << setw(15) << T[0][2] << setw(15) << T[0][3] << endl;
  cout << T[1][0] << setw(15) << T[1][1] << setw(15) << T[1][2] << setw(15) << T[1][3] << endl;
  cout << T[2][0] << setw(15) << T[2][1] << setw(15) << T[2][2] << setw(15) << T[2][3] << endl;
  cout << T[3][0] << setw(15) << T[3][1] << setw(15) << T[3][2] << setw(15) << T[3][3] << endl;

  cout << asin(-0.9) << endl;
  
  return 0;
}

void fkine(double q1, double q2, double q3, double q4, double q5, double q6)
{
  T[0][0] = cos(q1)*cos(q2)*cos(q3)*cos(q4)*cos(q5)*cos(q6)-sin(q1)*sin(q3)*cos(q4)*cos(q5)*cos(q6)-cos(q1)*sin(q2)*sin(q4)*cos(q5)*cos(q6)+cos(q1)*cos(q2)*sin(q3)*sin(q5)*cos(q6)+sin(q1)*cos(q3)*sin(q5)*cos(q6)+cos(q1)*cos(q2)*cos(q3)*sin(q4)*sin(q6)-sin(q1)*sin(q3)*sin(q4)*sin(q6)+cos(q1)*sin(q2)*cos(q4)*sin(q6);
  
  T[0][1] = -cos(q1)*cos(q2)*cos(q3)*cos(q4)*cos(q5)*sin(q6)+sin(q1)*sin(q3)*cos(q4)*cos(q5)*sin(q6)+cos(q1)*sin(q2)*sin(q4)*cos(q5)*sin(q6)-cos(q1)*cos(q2)*sin(q3)*sin(q5)*sin(q6)-sin(q1)*cos(q3)*sin(q5)*sin(q6)+cos(q1)*cos(q2)*cos(q3)*sin(q4)*cos(q6)-sin(q1)*sin(q3)*sin(q4)*cos(q6)+cos(q1)*sin(q2)*cos(q4)*cos(q6);
  
  T[0][2] = -cos(q1)*cos(q2)*cos(q3)*cos(q4)*sin(q5)+sin(q1)*sin(q3)*cos(q4)*sin(q5)+cos(q1)*sin(q2)*sin(q4)*sin(q5)+cos(q1)*cos(q2)*sin(q3)*cos(q5)+sin(q1)*cos(q3)*cos(q5);
  
  T[0][3] = -Lf*cos(q1)*cos(q2)*cos(q3)*sin(q4)+Lf*sin(q1)*sin(q3)*sin(q4)-Lf*cos(q1)*sin(q2)*cos(q4)+Lu*cos(q1)*sin(q2);
  
  T[1][0] = sin(q1)*cos(q2)*cos(q3)*cos(q4)*cos(q5)*cos(q6)+cos(q1)*sin(q3)*cos(q4)*cos(q5)*cos(q6)-sin(q1)*sin(q2)*sin(q4)*cos(q5)*cos(q6)+sin(q1)*cos(q2)*sin(q3)*sin(q5)*cos(q6)-cos(q1)*cos(q3)*sin(q5)*cos(q6)+sin(q1)*cos(q2)*cos(q3)*sin(q4)*sin(q6)+cos(q1)*sin(q3)*sin(q4)*sin(q6)+sin(q1)*sin(q2)*cos(q4)*sin(q6);
  
  T[1][1] = -sin(q1)*cos(q2)*cos(q3)*cos(q4)*cos(q5)*sin(q6)-cos(q1)*sin(q3)*cos(q4)*cos(q5)*sin(q6)+sin(q1)*sin(q2)*sin(q4)*cos(q5)*sin(q6)-sin(q1)*cos(q2)*sin(q3)*sin(q5)*sin(q6)+cos(q1)*cos(q3)*sin(q5)*sin(q6)+sin(q1)*cos(q2)*cos(q3)*sin(q4)*cos(q6)+cos(q1)*sin(q3)*sin(q4)*cos(q6)+sin(q1)*sin(q2)*cos(q4)*cos(q6);
  
  T[1][2] = -sin(q1)*cos(q2)*cos(q3)*cos(q4)*sin(q5)-cos(q1)*sin(q3)*cos(q4)*sin(q5)+sin(q1)*sin(q2)*sin(q4)*sin(q5)+sin(q1)*cos(q2)*sin(q3)*cos(q5)-cos(q1)*cos(q3)*cos(q5);
  
  T[1][3] = -Lf*sin(q1)*cos(q2)*cos(q3)*sin(q4)-Lf*cos(q1)*sin(q3)*sin(q4)-Lf*sin(q1)*sin(q2)*cos(q4)+Lu*sin(q1)*sin(q2);
  
  T[2][0] = -sin(q2)*cos(q3)*cos(q4)*cos(q5)*cos(q6)-cos(q2)*sin(q4)*cos(q5)*cos(q6)-sin(q2)*sin(q3)*sin(q5)*cos(q6)-sin(q2)*cos(q3)*sin(q4)*sin(q6)+cos(q2)*cos(q4)*sin(q6);
  
  T[2][1] = sin(q2)*cos(q3)*cos(q4)*cos(q5)*sin(q6)+cos(q2)*sin(q4)*cos(q5)*sin(q6)+sin(q2)*sin(q3)*sin(q5)*sin(q6)-sin(q2)*cos(q3)*sin(q4)*cos(q6)+cos(q2)*cos(q4)*cos(q6);
  
  T[2][2] = sin(q2)*cos(q3)*cos(q4)*sin(q5)+cos(q2)*sin(q4)*sin(q5)-sin(q2)*sin(q3)*cos(q5);
  
  T[2][3] = Lf*sin(q2)*cos(q3)*sin(q4)- Lf*cos(q2)*cos(q4)+Lu*cos(q2);
  T[3][0] = 0;
  T[3][1] = 0;
  T[3][2] = 0;
  T[3][3] = 1;
}
