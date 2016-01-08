#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include "Ikine.h"

int main()
{
  const double matrix[4][4] = {
    {-0.415,-0.496,-0.763,43.073},
    {0.653,-0.746,0.123,100.755},
    {-0.633,-0.444,0.634,-17.307},
    {0,0,0,1}
  };
  
  Ikine ikine( matrix );

  ikine.getEulerAngle();
  ikine.getQ6_0();
  //if ( (ikine.Q6_0[0][0] - 0.0) < 0.0001 )
  //  {
  //   ikine.Q6_0[0][0] = 0.0;
  // }
  ikine.getCosTheta4();
  ikine.getCosTheta5();
  ikine.getCosTheta6();

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

//cout << "x= : " << ikine.Q6_0[0][0] << endl;
//cout << "y= : " << ikine.Q6_0[1][0] << endl;
//cout << "z= : " << ikine.Q6_0[2][0] << endl;
  return 0 ;
}
