#include<stdio.h>
double a,b,c,d;
long cs=1;
int main()
{
	while(scanf("%lf%lf",&a,&b),(a||b))
	{
		c=b/a;
		d=(b-1)/(a-1);
		if(a==1.0)
		{
			printf("Case %ld: :-\\\n",cs++);
			continue;
		}

		if(c>1.0)
			c=1.0;
		if(d>1.0)
			d=1.0;

		if(c>d)
			printf("Case %ld: :-(\n",cs++);
		else if(c<d)
			printf("Case %ld: :-)\n",cs++);
		else
			printf("Case %ld: :-|\n",cs++);
	}
	return 0;
}