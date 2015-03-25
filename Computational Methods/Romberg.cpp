#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
using namespace std;
//ROmberg函数 约定a, b, n, ee为左右区间点，第一次复化分割份数，精确度
//rom[-1]为最后一个复化梯形积分结果，rom[0]是由Romberg公式递推的n份k阶复化积分结果

int n;
double a, b, ee, h, rom[MAX];

double gety(double x)
{
    //if (x==-1 || x==1) return 0;
    //return x*sin(x)/sqrt(1-x*x);
    //return cos(x)/sqrt(1-x);
    return 4/(1+x*x);
    //return x*x*pow(EE, x);
    //return pow(EE, x)*sin(x);
    //return 1/(1+x);
    //return sin(x)/x;
    //return (cos(x)-1)/sqrt(x);
    //return x*sin(x);
    //return pow(EE, -x*x);
    //return 1/((x+1)*sqrt(x));
    //return 2/(1+x*x);
}

double geth(void)
{
    n*=2;
    h=(b-a)/n;
    double sum=0;
    for (int i=1; i<=n/2; i++)
    {
        sum+=gety(a+(2*i-1)*h);
    }
    sum*=2;
    return sum*h/2;
}

void Romberg(int k)
{
    rom[k]=rom[k-1]/2+geth();
    printf("%d %lf\n", n, rom[k]);
    long long g=4;
    for (int i=k-1; i>0; i--)
    {
        rom[i]=(g*rom[i+1]-rom[i])/(g-1);
        g*=4;
    }
    //for (int i=0; i<=k; i++) printf("%lf ", rom[i]);
    //printf("\n");
    if (abs(rom[0]-rom[1])<ee) return;
    rom[0]=(g*rom[1]-rom[0])/(g-1);
    //printf("%d %lf\n", n, rom[0]);
    Romberg(k+1);
    return;
}

void doRomberge(void)
{
    h=(b-a)/n;
    memset(rom, 0, sizeof(rom));

    //count rom[0]
    double sum=0;
    for (int i=1; i<n; i++)
    {
        sum+=gety(a+i*h);
    }
    sum*=2;
    sum = sum+gety(a)+gety(b);
    rom[0] = sum*h/2;
    //printf("%lf\n", rom[0]);
    Romberg(1);
}

int main()
{
    scanf("%lf%lf%d%lf", &a, &b, &n, &ee);

    doRomberge();

    printf("%.10lf", rom[0]);
    return 0;
}
