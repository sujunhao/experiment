#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define MAX 10
#define EE 2.71828182846
#define PI 3.14159265359
#define ERROR -123
using namespace std;

int n;
double p[MAX][MAX];

//求多项式的系数
void getp(int n)
{
    memset(p, 0, sizeof(p));
    p[0][0]=p[1][1]=1;
    p[1][0]=0;
    for (int i=2; i<=n; i++)
    {
        for (int j=0; j<i; j++)
        {
            p[i][j+1] += (double)(2*i-1)/i*p[i-1][j];
            if (j<i-1) p[i][j] -= (double)(i-1)/i*p[i-2][j];
        }
    }
    for (int i=0; i<=n; i++)
    {
        printf("%d: ", i);
        for (int j=0; j<=i; j++)
        {
            printf("%lf  ", p[i][j]);
        }
        printf("\n");
    }
}
//求f(x)
double gety(double x)
{
    double sum=0;
    for (int i=0; i<=6; i++)
    {
        sum+=pow(x, i)*p[6][i];
    }
    return sum;

    //return cos(x)-x;
    //return exp(-x)-sin(x);
    //return x-exp(-x);
    //return x*x-2*x*exp(-x)+exp(-2*x);
}
//求f'(x)
double getyy(double x)
{
    double sum=0;
    for (int i=1; i<=6; i++)
    {
        sum+=pow(x, i-1)*p[6][i]*i;
    }
    return sum;
    //return -sin(x)-1;
    //return -exp(-x)-cos(x);
    //return 1+exp(-x);
    //return 2*x-2*(1-x)*exp(-x)-2*exp(-2*x);
}
//牛顿迭代法，不断迭代x=x-f(x)/f'(x)的值
double Newton_M(double x, double e1, double e2, int N)
{
    int n=1;
    double F, DF, x1=x, x2=x;
    while (n<=N)
    {
        F=gety(x1);
        DF=getyy(x1);
        if (abs(F)<e1) return x1;
        if (abs(DF)<e2) return ERROR;
        x2 = x1-F/DF;
        //printf("%lf\n", x2);
        if (abs(x1-x2)<e1) return x2;
        x1=x2;
        n++;
    }
    return ERROR;
}
int main()
{
    int N;
    double e1, e2, x, res;
    getp(6);
    
    e1=0.00000001;
    e2=0.0001;
    N=20;
    stack<double> s;
    for (double i=-3; i<3; i+=0.1)
    {
        x=i;
        res = Newton_M(x, e1, e2, N);
        if (res==ERROR)     continue;
            //printf("error!");
        else if (s.empty() || abs(s.top()-res)>e2) s.push(res);
            //printf("%lf \nand f(x)=%lf\n", res, gety(res));
    }
    while (!s.empty())
    {
        printf("%.10lf\n", s.top());
        s.pop();
    }





    return 0;
}
