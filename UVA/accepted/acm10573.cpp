#include<stdio.h>
#include<math.h>
# define pi 2*acos(0)
int main()
{
	double r1,r2,area;
	long n;
	char c;
	
	scanf("%ld",&n);
	

	while(n--)
	{
		scanf("%lf%c",&r1,&c);
		if(c==' ')
		{
			scanf("%lf",&r2);
			area=(pi*r1*r1)+(pi*r2*r2);
			r1+=r2;
			area-=(pi*r1*r1);
		}
		else
		{
			r1/=2;
			area=pi*r1*r1;
			r1/=2;
			area-=(2*pi*r1*r1);
		}
		if(area<0)
			area*=-1;
		printf("%.4lf\n",area);
	}

	return 0;
}
