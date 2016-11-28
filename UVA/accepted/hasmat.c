#include<stdio.h>

double a,b,c;

int main()
{
	while(~scanf("%lf%lf",&a,&b))
	{
		if(b>a)
		{
		c=b-a;
		printf("%.0lf\n",c);
		}
		else
		{
			c=a-b;
			printf("%.0lf\n",c);
		}
	}
	return 0;
}