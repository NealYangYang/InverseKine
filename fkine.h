#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

class Fkine
{
 public:
  
  Fkine();

  double T[4][4];

  void getFkine(double q1, double q2, double q3, double q4, double q5, double q6);
  void showResult();
  
 private:
  double pi = 180;
  double Lu = 50.0;
  double Lf = 70.0;
  
};
