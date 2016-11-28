#include<stdio.h>
#include<math.h>
long t,cs=1;
double r,area;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%lf",&r);

		area=4.0*(r*r);

		area-=2.0*acos(0)*r*r;

		printf("Case %ld: %.2lf\n",cs++,area+1e-9);
	}
	return 0;
}