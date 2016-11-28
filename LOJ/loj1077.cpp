#include<stdio.h>
long long x1,y1,x2,y2,t,cs=1;

long long gcd(long long a,long long b)
{
	long long c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);

		x1=x1-x2;
		if(x1<0)
			x1*=-1;

		y1=y1-y2;
		if(y1<0)
			y1*=-1;
		if(x1==0)
		x1=y1;
		else if(y1==0);
		else
		x1=gcd(x1,y1);

		printf("Case %lld: %lld\n",cs++,x1+1);
	}
	return 0;
}
