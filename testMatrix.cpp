//构造矩阵类，重载乘法操作符
//作者：nuaazdh
//时间：2011年12月1日

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

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
  Matrix B(m,n);
  for(i=0;i<m;i++)//动态数组赋值
            for(j=0;j<n;j++)
              B.data[i][j]=A[i][j];
  B.display();
  return 0;
}
