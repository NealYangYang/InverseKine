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
      {0.862, -0.506, -0.007, -24.147},
      {0.503, 0.857, 0.121, 18.918},
      {-0.055, -0.108, 0.993, 3.941},
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
  /*
  cout << endl;
  
    for ( int i = 0; i < 8; i ++ )
    {
      cout << "****RealSolution" << i+1 << "****" << endl;
      for ( int j = 3; j < 6; j ++ )
	{
	  cout << "Theta" << j+1 << " :"  << ikine.SolR[i][j]* 180 / M_PI  << endl;}
      cout << endl;
    }
  */
  Fkine fkine;
  fkine.getFkine(23,85,-79,23,19,120);
  fkine.showResult();
  ikine.getTheta1_3(ikine.T0_3_1, 1);
  ikine.getTheta1_3(ikine.T0_3_2, 2);
  ikine.getTheta1_3(ikine.T0_3_3, 3);
  ikine.getTheta1_3(ikine.T0_3_4, 4);
  
  
  cout << endl;
 for ( int i = 0; i < 8; i ++ )
    {
      cout << "****RealSolution" << i+1 << "****" << endl;
      for ( int j = 0; j < 6; j ++ )
	{
	  cout << "Theta" << j+1 << " :"  << ikine.SolR[i][j]* 180 / M_PI  << endl;}
      cout << endl;
    }
  cout << endl;
  
  
  /*
  cout << ikine.alfa *180/M_PI<< endl;
  cout << ikine.beta *180/M_PI << endl;
  cout << ikine.gama *180/M_PI << endl;
  */
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
