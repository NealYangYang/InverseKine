#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cmath>
#include "fkine.h"

Fkine::Fkine()
{
  pi = 180;
  Lu = 50;
  Lf = 70;
}

void Fkine::getFkine(double q1, double q2, double q3, double q4, double q5, double q6)
{
  q1 = q1/pi*M_PI;
  q2 = q2/pi*M_PI;
  q3 = q3/pi*M_PI;
  q4 = q4/pi*M_PI;
  q5 = q5/pi*M_PI;
  q6 = q6/pi*M_PI;
  
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

void Fkine::showResult()
{
  cout << T[0][0] << setw(15) << T[0][1] << setw(15) << T[0][2] << setw(15) << T[0][3] << endl;
   cout << T[1][0] << setw(15) << T[1][1] << setw(15) << T[1][2] << setw(15) << T[1][3] << endl;
    cout << T[2][0] << setw(15) << T[2][1] << setw(15) << T[2][2] << setw(15) << T[2][3] << endl;
     cout << T[3][0] << setw(15) << T[3][1] << setw(15) << T[3][2] << setw(15) << T[3][3] << endl;
  
  
}
