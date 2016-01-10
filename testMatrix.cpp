//构造矩阵类，重载乘法操作符
//作者：nuaazdh
//时间：2011年12月1日

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;

#include "Matrix.h"

//主函数
int main(int argc, char* argv[])
{
  int m = 4;
  int n = 4;
  int i,j;
  
  double A[4][4] =
    {
      {0,0,1,0},
      {0,1,0,70},
      {1,0,0,50},
      {0,0,0,0}
    };

  double B[4][4] =
    {
      {1,0,0,1},
      {0,0,1,0},
      {1,0,1,0},
      {0,1,0,1}
    };

  double C[4][4];
  
   Matrix a(4,4);
   for(i=0;i<m;i++)//动态数组赋值
     for(j=0;j<n;j++)
       a.data[i][j]=A[i][j];
         
   Matrix b(4,4);
   for(i=0;i<m;i++)//动态数组赋值
     for(j=0;j<n;j++)
       b.data[i][j]=B[i][j];

   Matrix c = a * b;
   for(i=0;i<m;i++)//动态数组赋值
     for(j=0;j<n;j++)
       C[i][j]=c.data[i][j];

   a.display();
   b.display();

   cout << C[0][0] << setw(10) << C[0][1] << setw(10) << C[0][2] << setw(10) << C[0][3] << endl;

   cout << C[1][0] << setw(10) << C[1][1] << setw(10) << C[1][2] << setw(10) << C[1][3] << endl;

   cout << C[2][0] << setw(10) << C[2][1] << setw(10) << C[2][2] << setw(10) << C[2][3] << endl;

   cout << C[3][0] << setw(10) << C[3][1] << setw(10) << C[3][2] << setw(10) << C[3][3] << endl;
   
   return 0;
}
