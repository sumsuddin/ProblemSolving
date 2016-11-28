#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795
int main()
{
	long double n,area,ans1,ans2,r;
	long p=1;

	while(scanf("%llf%llf",&n,&area) && n>=3)
	{
		r=sqrt((2*area)/(n*sin((2*pi)/n)));

		ans1=pi*r*r-area;

		r=sqrt(area/(n*tan(pi/n)));
		ans2=area-pi*r*r;
		printf("Case %ld: %.5llf %.5llf\n",p++,ans1,ans2);
	}
	return 0;
}