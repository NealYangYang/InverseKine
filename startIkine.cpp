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
      {-0.098, -0.821, -0.563, 35.305},
      {-0.993,0.118,-0.000,-13.007},
      {0.067,0.559,-0.827,6.931},
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
  
  cout << endl;
  
    for ( int i = 0; i < 8; i ++ )
    {
      cout << "****RealSolution" << i+1 << "****" << endl;
      for ( int j = 3; j < 6; j ++ )
	{
	  cout << "Theta" << j << " :"  << ikine.SolR[i][j]* 180 / M_PI  << endl;}
      cout << endl;
    }

  Fkine fkine;
  fkine.getFkine(104,43,-123,-32,105,-34.4);
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
