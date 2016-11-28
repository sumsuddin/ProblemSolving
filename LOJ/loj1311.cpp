#include<stdio.h>
long cs=1,t;
double v1,v2,v3,d,tm,a1,a2;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
		
		d=((v1*v1)/(2*a1))+((v2*v2)/(2*a2));
		tm=v1/a1;
		if(v2/a2>tm)
			tm=v2/a2;
		tm*=v3;
		printf("Case %ld: %lf %lf\n",cs++,d,tm);
	}
	return 0;
}