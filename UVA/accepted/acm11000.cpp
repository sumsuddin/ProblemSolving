#include<stdio.h>

int main()
{
	long double a,b,c,n;
	while(scanf("%llf",&n) && n!=-1)
	{
		a=1;
		b=2;
		while(n--)
		{
			c=b;
			b+=a;
			a=c;

		}
		a--;b--;
		printf("%.0llf %.0llf\n",a,b);
	}
	return 0;
}