#include <iostream>
using std::endl;
using std::cout;

class MotorOutput
{
 public:

  int initPos1;
  int initPos2;
  int initPos3;
  int initPos4;
  char serialOutputICS[10];
  char serialOuputServo[4];
  
  MotorOutput(int pos1, int pos2, int pos3, int pos4);
  void setPosition(double angle[6]);

  
 private:
  double minAngle;
  double maxAngle;
  double minAngleNum;
  double stdAngleNum;
  double maxAngleNum;
  
};
