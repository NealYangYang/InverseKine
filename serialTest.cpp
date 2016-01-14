#include <iostream>
using std::endl;
using std::cout;
using std::hex;

#include "serialOutput.h"

int main()
{

  double angle[6] = {13, 14, 90, 12, 15, 90};
  MotorOutput output(7500,7500,7500,7500);
  output.setPosition(angle);
  
  for (int i = 0; i < 10; i++)
    {
      cout << hex << (int)output.serialOutputICS[i] << endl;
    }

  cout << endl;

  output.calPosition(9000);
  return 0;
}
