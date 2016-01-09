//构造矩阵类，重载乘法操作符
//作者：nuaazdh
//时间：2011年12月1日

#include <iostream>

using namespace std;

//Matrix矩阵类
class Matrix
{
public:
    Matrix(int mm, int nn)//构造函数
    {
        m=mm;
        n=nn;
        int i,j;
        data=new double*[mm];
        for(i=0;i<mm;i++)
            data[i]=new double[nn];
        for(i=0;i<m;i++)//矩阵所有元素清零
            for(j=0;j<n;j++)
                data[i][j]=0.0;
    } //构造M行N列的矩阵

    Matrix(const Matrix &src) //拷贝构造函数
    {
        m=src.m;
        n=src.n;
          int i,j;
        data=new double*[m];//动态建立二维数组
        for(i=0;i<m;i++)
            data[i]=new double[n];
        for(i=0;i<m;i++)//动态数组赋值
            for(j=0;j<n;j++)
                data[i][j]=src.data[i][j];
    }

    ~Matrix()//析构函数
    {
        for(int i=0;i<m;i++)
            delete []data[i];
        delete []data;
    }
    Matrix& operator=(const Matrix &src);//重载"="运算符
    Matrix operator * (const Matrix &m2); //矩阵乘法
    void display();
    void input();
    private:
        double **data;
    int m,n;//矩阵的行数，列数
};//类定义结束

Matrix& Matrix::operator=(const Matrix &src) //重载"="运算符
{
    int i,j;
    for(i=0;i<m;i++)
        delete []data[i];
    delete []data;
    m=src.m;n=src.n;
    data=new double*[m];//动态建立二维数组
    for(i=0;i<m;i++)
        data[i]=new double[n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            data[i][j]=src.data[i][j];
    return *this;
}

//矩阵*运算符重载
Matrix Matrix::operator *(const Matrix &m2)//矩阵乘法的实现
{
    Matrix m3(this->m,m2.n);
    if(this->n!=m2.m)
    {
        cout<<"两矩阵无法进行乘法运算.\n"<<endl;
        exit(0);
    }
    int i,j,k,l;
    for(i=0;i<this->m;i++)
        for(j=0;j<m2.n;j++)
        {
            for(k=0;k<this->n;k++)
             {
                m3.data[i][j]+=this->data[i][k]*m2.data[k][j];
             }

        }
    return m3;
}

//输入矩阵元素
void Matrix::input()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>data[i][j];
}

//显示矩阵元素
void Matrix::display()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

//主函数
int main(int argc, char* argv[])
{
    int x,y;
    cout<<"矩阵1行数:";
    cin>>x;
    cout<<"矩阵1列数:";
    cin>>y;
    Matrix A(x,y);
    cout<<"请输入矩阵1元素（按行，共"<<x*y<<" 个）"<<endl;
    A.input();
    cout<<"矩阵1："<<endl;
    A.display();
    cout<<"矩阵2行数:";
    cin>>x;
    cout<<"矩阵2列数:";
    cin>>y;
    Matrix B(x,y);
    cout<<"请输入矩阵2元素（按行，共"<<x*y<<" 个）"<<endl;
    B.input();
    cout<<"矩阵2："<<endl;
    B.display();
    Matrix C=A*B;
    cout<<"矩阵1 与 矩阵2 的乘积："<<endl;
    C.display();
    return 0;
}
