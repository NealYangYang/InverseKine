#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include "Ikine.h"
#include "fkine.h"

int main()
{
  double matrix[4][4] = {
    {0,0,1,-50},
    {-1,0,0,0},
    {0,-1,0,70},
    {0,0,0,1}
  };
  
  Ikine ikine( 50.0, 70.0 );
  ikine.setMatrix( matrix );
  ikine.getIkine();
//cout << "alfa :" << ikine.alfa * 180 / M_PI << endl;
//cout << "beta :" << ikine.beta * 180 / M_PI << endl;
//cout << "gama :" << ikine.gama * 180 / M_PI << endl;

  cout << "********Solution1********" << endl;
  cout << "Theta4_1 :" << ikine.Theta4_1 * 180 / M_PI << endl;
  cout << "Theta5_1_1 :" << ikine.Theta5_1_1 * 180 / M_PI << endl;
  cout << "Theta6_1_1 :" << ikine.Theta6_1_1 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution2********" << endl;
  cout << "Theta4_1 :" << ikine.Theta4_1 * 180 / M_PI << endl;
  cout << "Theta5_1_1 :" << ikine.Theta5_1_1 * 180 / M_PI << endl;
  cout << "Theta6_1_2 :" << ikine.Theta6_1_2 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution3********" << endl;
  cout << "Theta4_1 :" << ikine.Theta4_1 * 180 / M_PI << endl;
  cout << "Theta5_1_2 :" << ikine.Theta5_1_2 * 180 / M_PI << endl;
  cout << "Theta6_2_1 :" << ikine.Theta6_2_1 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution4********" << endl;
  cout << "Theta4_1 :" << ikine.Theta4_1 * 180 / M_PI << endl;
  cout << "Theta5_1_2 :" << ikine.Theta5_1_2 * 180 / M_PI << endl;
  cout << "Theta6_2_2 :" << ikine.Theta6_2_2 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution5********" << endl;
  cout << "Theta4_2 :" << ikine.Theta4_2 * 180 / M_PI << endl;
  cout << "Theta5_2_1 :" << ikine.Theta5_2_1 * 180 / M_PI << endl;
  cout << "Theta6_3_1 :" << ikine.Theta6_3_1 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution6********" << endl;
  cout << "Theta4_2 :" << ikine.Theta4_2 * 180 / M_PI << endl;
  cout << "Theta5_2_1 :" << ikine.Theta5_2_1 * 180 / M_PI << endl;
  cout << "Theta6_3_2 :" << ikine.Theta6_3_2 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution7********" << endl;
  cout << "Theta4_2 :" << ikine.Theta4_2 * 180 / M_PI << endl;
  cout << "Theta5_2_2 :" << ikine.Theta5_2_2 * 180 / M_PI << endl;
  cout << "Theta6_4_1 :" << ikine.Theta6_4_1 * 180 / M_PI << endl;
  cout << endl;

  cout << "********Solution8********" << endl;
  cout << "Theta4_2 :" << ikine.Theta4_2 * 180 / M_PI << endl;
  cout << "Theta5_2_2 :" << ikine.Theta5_2_2 * 180 / M_PI << endl;
  cout << "Theta6_4_2 :" << ikine.Theta6_4_2 * 180 / M_PI << endl;
  cout << endl;

  Fkine fkine;
  fkine.getFkine(23,34,23,12,44,-65);
  fkine.showResult();
  ikine.getEulerAngle();
  cout << ikine.alfa * 180 / M_PI << endl;
  cout << ikine.beta * 180 / M_PI << endl;
  cout << ikine.gama * 180 / M_PI << endl;
  cout << endl;
  cout << ikine.R0_6[2][0] << endl;
  cout << ikine.R0_6[0][1] << endl;
  cout << ikine.R0_6[1][2] << endl;
  
  return 0 ;
}
