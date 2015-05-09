#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#define MOD 100
#define MAX 10000
#define GN 12

using namespace std;

double a[MAX], b[MAX];

int myscanf(double x[])
{
	int i=0;  
    char c;
    bool flag=1; 
    double K; 
    string str="", ss="";  
    while((c=getchar())!='~')  
    {  
    	if(c=='.')
    	{
    		flag=0; 
    		K=1;
    		continue;
    	}
        if(flag && c>='0'&&c<='9')  
        {  
            str += c;  
        }
        if (!flag && c>='0'&&c<='9')  
        {  
            ss += c;  
            K/=10;
        }
        else if(c =='\n')  
        {  
            x[i++] = atoi(str.c_str())+atoi(ss.c_str())*K;  
            str = "";  
            ss = "";
        }  
    }
    return i;
} 

int main()
{  
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int m, n;  
    m=myscanf(a); 
    getchar();
    n=myscanf(b);
    if (m!=n) {printf("error"); return 0;}

	double sum1=0, sum2=0, g1=0, g2=0;
    for(int j=0;j<m;j++)  
    {  
    	printf("a[%2d]: %.3lf   b[%2d]: %.3lf\n", j, a[j], j, b[j]);
    	sum1 += a[j];
    	sum2 += b[j];
    	g1+=log(a[j]);
    	g2+=log(b[j]);
    }  
    sort(a, a+m);
    sort(b, b+n);

    double range1 = a[m-1]-a[0], range2 = b[m-1]-b[0];
    double r1=range1/GN, r2=range2/GN, k1, k2;
    k1=((a[0]-r1/2)>0?(a[0]-r1/2):0);
    k2=((b[0]-r2/2)>0?(b[0]-r2/2):0);
    int i=0, j=0;
    printf("\nT/N groups:\n%.2f ~ :", k1);
    for (; k1<a[m-1]; k1+=r1)
    {
        int num=0;
        while (i<m && a[i]>=k1 && a[i]<k1+r1) {num++; i++;}
        printf("%d\n", num);
        printf("%.2f ~ :", k1+r1);
    }
    printf("\nMeIT-MelN groups:\n%.2f ~ :", k2);
    for (; k2<b[m-1]; k2+=r2)
    {
        int num=0;
        while (j<m && b[j]>=k2 && b[j]<k2+r2) {num++; j++;}
        printf("%d\n", num);
        printf("%.2f ~ :", k2+r2);
    }
   	double ave1=sum1/m, ave2=sum2/n, s1=0, s2=0, am2=0, am3=0, am4=0, bm2=0, bm3=0, bm4=0;
    for (int i=0; i<m; i++)
    {
    	s1 += (a[i]-ave1)*(a[i]-ave1);
    	am3 += pow((a[i]-ave1), 3);
    	am4 += pow((a[i]-ave1), 4);
    	s2 += (b[i]-ave2)*(b[i]-ave2);
    	bm3 += pow((b[i]-ave2), 3);
    	bm4 += pow((b[i]-ave2), 4);
    }
    am2 = s1/m;
    bm2 = s2/m;
    am3 /= m;
    bm3 /= m;
    am4 /= m;
    bm4 /= m;
    printf("\n\n          T/N | MeIT-MelN\n");
    printf("size : %6d    %6d\n", m, n);
    printf("max  : %5.5lf    %5.5lf\n", a[m-1], b[m-1]);
    printf("min  : %5.5lf    %5.5lf\n", a[0], b[0]);
    printf("range: %5.5lf    %5.5lf\n", a[m-1]-a[0], b[m-1]-b[0]);
    printf("-y-  : %5.5lf    %5.5lf\n", ave1, ave2);
    printf("G    : %5.5lf    %5.5lf\n", exp(g1/m), exp(g2/m));
    printf("M    : %5.5lf    %5.5lf\n", a[m/2],  b[m/2]);
    printf("sd   : %5.5lf    %5.5lf\n", sqrt(s1/m), sqrt(s2/m));
    printf("s    : %5.5lf    %5.5lf\n", sqrt(s1/(m-1)), sqrt(s2/(m-1)));
    printf("CV   : %5.5lf    %5.5lf\n", sqrt(s1/(m-1))/ave1, sqrt(s2/(m-1))/ave2 );
   	printf("g1   : %5.5lf    %5.5lf\n", am3/pow(am2, 1.5), bm3/pow(bm2, 1.5));
   	printf("g2   : %5.5lf    %5.5lf\n", am4/(am2*am2) - 3, bm4/(bm2*bm2) - 3);


    printf("若舍弃5.220这个明显偏大的值");

    return 0;
}
