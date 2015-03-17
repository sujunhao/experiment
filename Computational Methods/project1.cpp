#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
using namespace std;


double num[MAX], x, y, xx[MAX];
int  n=1, k, xn, nn;

double Lagrange(const double x, int n, double num[]) //Lagrange��ֵ num[]��n����֪�㣬 1~n/2Ϊxi,n/2+1~nΪyi xΪ�Ա���
{
    double y=0;
    for (int i=1; i<=n/2; i++){
            double l=1, xi=num[i], xj=0;
            for (int j=1; j<=n/2; j++){
                if (j==i) continue;
                xj=num[j];
                l = l*(x-xj)/(xi-xj);
            }
            y+=l*num[i+n/2];
           //printf("%d %lf %lf %lf %lf\n", i, num[i], num[i+n/2], l, y);
    }
    return y;
}

double get(double x)
{
    //return 1/(1+x*x);
    return pow(EE, x);
    //return sqrt(x);
}

double getxk(int i, int n)
{
    return cos((2*i+1)*(PI)/(2*(n+1)));
}
int main()
{
    printf("����xi������ xiֵ�� �ָ����� \n");
    scanf("%d", &xn);
    for (int i=0; i<xn; i++) scanf("%lf", &xx[i]);
    //scanf("%d", &nn);
    //for (int i=0; i<nn; i++) scanf("%lf", &num[i+1]);
    while (~scanf("%d", &k)){
    //k=nn-1;
    for (int f=0; f<xn; f++){
    x=xx[f];
    //double h=(2.0)/k;
    for (int i=0; i<=k; i++)
    {
        //num[i+1]=(-1)+i*h;
        num[i+1]=getxk(i, k);
        num[i+2+k]=get(num[i+1]);
        //printf("%d %lf %lf\n", i+1, num[i+1], num[i+2+k]);
    }
    y=Lagrange(x, 2*k+2, num);
    printf("x=%lf y=%lf\n", x, y);
    }
    }
    printf("��ȷֵ��\n");
    for (int i=0; i<xn; i++){
        printf("x=%lf y=%lf\n",xx[i],get(xx[i]));
    }
    return 0;
}
