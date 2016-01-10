#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include <iomanip>
using std::setw;

#include "Ikine.h"
#include "Fkine.h"

int main()
{
  double matrix[4][4] = 
    {
      {0.941, -0.067, 0.332, -58.128},
      {-0.337, -0.095, 0.937, 11.313},
      {-0.032, -0.993, -0.112, 37.210},
      {0,0,0,1}
      
    };
  
  Ikine ikine( 50.0, 70.0 );
  ikine.setMatrix( matrix );
  ikine.getIkine();
//cout << "alfa :" << ikine.alfa * 180 / M_PI << endl;
//cout << "beta :" << ikine.beta * 180 / M_PI << endl;
//cout << "gama :" << ikine.gama * 180 / M_PI << endl;
/*
  for ( int i = 0; i < 8; i ++ )
    {
      cout << "****Solution" << i+1 << "****" << endl;
      for ( int j = 3; j < 6; j ++ )
	{
	  cout << "Theta" << j << " :"  << ikine.Sol[i][j]* 180 / M_PI  << endl;}
      cout << endl;
    }
*/
  cout << endl;
  
    for ( int i = 0; i < 8; i ++ )
    {
      cout << "****RealSolution" << i+1 << "****" << endl;
      for ( int j = 3; j < 6; j ++ )
	{
	  cout << "Theta" << j+1 << " :"  << ikine.SolR[i][j]* 180 / M_PI  << endl;}
      cout << endl;
    }

  Fkine fkine;
  fkine.getFkine(125,-15,39,-69,16,101);
  fkine.showResult();

  cout << endl;
  cout << ikine.Theta1_1 * 180 / M_PI << endl;
  cout << ikine.Theta2_1 * 180 / M_PI << endl;
  cout << ikine.Theta3_1 * 180 / M_PI << endl;
  cout << endl;
  cout << ikine.Theta1_2 * 180 / M_PI << endl;
  cout << ikine.Theta2_2 * 180 / M_PI << endl;
  cout << ikine.Theta3_2 * 180 / M_PI << endl;
  cout << endl;
  
  cout << ikine.alfa *180/M_PI<< endl;
  cout << ikine.beta *180/M_PI << endl;
  cout << ikine.gama *180/M_PI << endl;
 
  /*
    for (int i = 0; i < 4; i++ )
    {
      for (int j = 0; j < 4; j++ )
	{
	  cout << setw(15) << ikine.T0_3[i][j];
	  if (j == 3)
	    {
	      cout << endl;
	    }
	}
    }
  */
  return 0 ;
}
