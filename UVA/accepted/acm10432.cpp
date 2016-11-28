#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832
int main()
{
	double r,n,a,b,area;

	while(scanf("%lf%lf",&r,&n)==2)
	{
		area=sin(pi/n)*cos(pi/n)*r*r*n;
		printf("%.3lf\n",area);
	}
	return 0;
}