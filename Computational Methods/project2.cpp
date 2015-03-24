#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
using namespace std;

int n;
double a, b, ee, h, rom[MAX];

double gety(double x)
{
    return 4/(1+x*x);
    //return x*x*pow(2.71828182846, x);
}

double geth(void)
{
    n*=2;
    h=(b-a)/n;
    double sum=0;
    for (int i=0; i<=n; i++)
    {
        sum+=gety(a+i*h);
    }
    sum*=2;
    sum = sum-gety(a)-gety(b);
    return sum*h/2;
}



void Romberg(int k)
{
    rom[k]=geth();
    long long g=4;
    for (int i=k-1; i>0; i--)
    {
        rom[i]=(g*rom[i+1]-rom[i])/(g-1);
        g*=4;
    }
    for (int i=0; i<=k; i++) printf("%lf ", rom[i]);
    printf("\n");
    if (abs(rom[0]-rom[1])<ee) return;
    rom[0]=(g*rom[1]-rom[0])/(g-1);
    Romberg(k+1);
    return;
}

int main()
{
    scanf("%lf%lf%d%lf", &a, &b, &n, &ee);
    h=(b-a)/n;
    memset(rom, 0, sizeof(rom));

    //count rom[0]
    double sum=0;
    for (int i=0; i<=n; i++)
    {
        sum+=gety(a+i*h);
    }
    sum*=2;
    sum = sum-gety(a)-gety(b);
    rom[0] = sum*h/2;
    printf("%lf\n", rom[0]);

    Romberg(1);
    printf("%.10lf", rom[0]);
    return 0;
}
