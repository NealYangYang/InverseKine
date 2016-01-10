#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include "Ikine.h"
#include "Fkine.h"

int main()
{
  double matrix[4][4] = 
    {
      {0.817, -0.139, -0.560, 26.146},
      {-0.354,-0.887,-0.296,27.701},
      {-0.456,0.440,-0.774,3.563},
      {0,0,0,1}
    };
  
  Ikine ikine( 50.0, 70.0 );
  ikine.setMatrix( matrix );
  ikine.getIkine();
//cout << "alfa :" << ikine.alfa * 180 / M_PI << endl;
//cout << "beta :" << ikine.beta * 180 / M_PI << endl;
//cout << "gama :" << ikine.gama * 180 / M_PI << endl;

  for ( int i = 0; i < 8; i ++ )
    {
      cout << "****Solution" << i+1 << "****" << endl;
      for ( int j = 3; j < 6; j ++ )
	{
	  cout << "Theta" << j << " :"  << ikine.Sol[i][j]* 180 / M_PI  << endl;}
      cout << endl;
    }
  
  Fkine fkine;
  fkine.getFkine(34,-20,13,-32,105,-34.4);
  fkine.showResult();
  ikine.getEulerAngle();
  cout << "alfa :" << ikine.alfa * 180 / M_PI << endl;
  cout << "beta :" << ikine.beta * 180 / M_PI << endl;
  cout << "gama :" << ikine.gama * 180 / M_PI << endl;
  cout << endl;
  cout << ikine.Q6_0[0][0] << endl;
  cout << ikine.Q6_0[1][0] << endl;
  cout << ikine.Q6_0[2][0] << endl;
  return 0 ;
}
