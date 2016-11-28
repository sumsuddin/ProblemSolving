#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795028841971693993751058209749445
double a,d;
int main()
{
	while(scanf("%lf%lf",&d,&a) && ( d!=0.0 && a!=0.0))
	{
		printf("%.3lf\n",pow(((pow(d,3)-((6.0*a)/pi))),1.0/3.0));
	}
	return 0;
}