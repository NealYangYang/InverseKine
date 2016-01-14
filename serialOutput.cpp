#include <iostream>
using std::endl;
using std::cout;
using std::hex;

#include "serialOutput.h"

MotorOutput::MotorOutput(int pos1, int pos2, int pos3, int pos4)
{
  minAngle = -135;
  maxAngle = 135;
  minAngleNum = 3500;
  stdAngleNum = 7500;
  maxAngleNum = 11500;
  initPos1 = pos1;
  initPos2 = pos2;
  initPos3 = pos3;
  initPos4 = pos4;
  
}

void MotorOutput::setPosition(double angle[6])
{

  int angle1[10];
  for (int i = 0; i < 4; i++)
    {
      if(angle[i] < 0)
	{
	  angle1[i] = (int)(stdAngleNum - angle[i] / minAngle * (maxAngleNum - stdAngleNum));
	}else{
	angle1[i] = (int)(stdAngleNum + angle[i] /maxAngle * (maxAngleNum - stdAngleNum));
      }    
    }
  
  int q1[3][1]={{angle1[0]},{angle1[1]},{1}};
  int e1[2][3]={{-1,-1,initPos1},{-1,1,initPos2}};
  int m1[2][1]={{q1[0][0]*e1[0][0]+q1[1][0]*e1[0][1]+q1[2][0]*e1[0][2]},{q1[0][0]*e1[1][0]+q1[1][0]*e1[1][1]+q1[2][0]*e1[1][2]}};

  int q2[3][1]={{angle1[2]},{angle1[3]},{1}};
  int e2[2][3]={{-1,-1,initPos3},{-1,1,initPos4}};
  int m2[2][1]={{q2[0][0]*e2[0][0]+q2[1][0]*e2[0][1]+q2[2][0]*e2[0][2]},{q2[0][0]*e2[1][0]+q2[1][0]*e2[1][1]+q2[2][0]*e2[1][2]}};

  serialOutputICS[0] = 0x40;
  serialOutputICS[1] = 0x5c;
  
  serialOutputICS[2] = (m1[0][0] >> 7) & 0x7F;
  serialOutputICS[3] = m1[0][0] & 0x7f;

  serialOutputICS[4] = (m1[1][0] >> 7) & 0x7F;
  serialOutputICS[5] = m1[1][0] & 0x7f;

  serialOutputICS[6] = (m2[0][0] >> 7) & 0x7F;
  serialOutputICS[7] = m2[0][0] & 0x7f;

  serialOutputICS[8] = (m2[1][0] >> 7) & 0x7F;
  serialOutputICS[9] = m2[1][0] & 0x7f;
}

void MotorOutput::calPosition(int angle)
{
  int H = (angle >> 7) & 0x7F;
  int L = angle & 0x7f;
  cout << "H :" << hex << H << endl;
  cout << "L :" << hex << L << endl;
}
