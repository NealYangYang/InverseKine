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
      {-0.681074,      0.0470896,       0.730698,       -52.4485},
      {-0.731635,    -0.00406989,      -0.681685,       0.306177},
      {-0.0291264,      -0.998882,      0.0372243,        69.0741},
      {0,0,0,1}
      
    };
  
  Ikine ikine( 50.0, 70.0 );
  ikine.setMatrix( matrix );
  ikine.getIkine();

  Fkine fkine;
  fkine.getFkine(1,-91,1,-91,46,1);
  fkine.showResult();
  
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
  
  
  for ( int i = 0; i < 8; i ++)
    {
      fkine.getFkine(ikine.SolR[i][0]*180/M_PI,ikine.SolR[i][1]*180/M_PI,ikine.SolR[i][2]*180/M_PI,ikine.SolR[i][3]*180/M_PI,ikine.SolR[i][4]*180/M_PI,ikine.SolR[i][5]*180/M_PI);
      fkine.showResult();
      cout << endl;
    }
  return 0 ;
}
