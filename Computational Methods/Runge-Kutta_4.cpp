#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define ERROR -123
using namespace std;
double a, b, yy, x, y, h, K1, K2, K3, K4;
int N, nn[]={5, 10, 20};


//4阶龙格-库塔法 
double gety(double x, double y)
{
    //return x+y;
    //return -(y*y);
    //return 2*y/x+x*x*exp(x);
    //return (y+1)*y/x;
    //return -20*(y-x*x)+2*x;
    //return -20*y+20*sin(x)+cos(x);
    return -20*(y-exp(x)*sin(x))+exp(x)*(sin(x)+cos(x));
}

double get_right_y(double x)
{
    //return -x-1;
    //return 1/(1+x);
    //return x*x*(exp(x)-exp(1));
    //return 2*x/(1-2*x);
    //return x*x+exp(-20*x)/3;
    //return exp(-20*x)+sin(x);
    sreturn exp(x)*sin(x);
}

int main()
{
    scanf("%lf%lf%lf", &a, &b, &yy);
    for (int k=0; k<3; k++)
    {
        N=nn[k];
        printf("N=%d\n", nn[k]);
        x = a, y = yy, h = (b-a)/N;
        for (int i=1; i<=N; i++)
        {
            K1 = h*gety(x, y);
            K2 = h*gety(x+h/2, y+K1/2);
            K3 = h*gety(x+h/2, y+K2/2);
            K4 = h*gety(x+h, y+K3);
            x = x+h;
            y = y + (K1+2*K2+2*K3+K4)/6;
            printf("%d %lf %lf  the right answer is :%lf %.15lf\n", i, x, y, get_right_y(x), abs(y-get_right_y(x)));
        }
    }


    return 0;
}
