#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s;

	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		if(a && b && c)
		{
			s=(a+b+c)/2;
			s=sqrt(s*(s-a)*(s-b)*(s-c))/s;
			printf("The radius of the round table is: %.3lf\n",s);
		}
		else
			printf("The radius of the round table is: 0.000\n");
	}
	return 0;
}