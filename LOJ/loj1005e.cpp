#include<stdio.h>
long i,n,r,cs=1,c,t;
long double d;
long double ncr(long n,long r)
{
	long double e;
		c=n-r;
		d=e=1;
		if(c>r)
		{
			for(i=c+1;i<=n;i++)
				d*=i;
			for(i=1;i<=r;i++)
				e*=i;
		}
		else
		{
			for(i=r+1;i<=n;i++)
				d*=i;
			for(i=1;i<=c;i++)
				e*=i;
		}
		d/=e;
	return d;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&r);

		d=ncr(n,r);

		for(i=n;i>n-r;i--)
			d*=i;
		printf("Case %ld: %.0llf\n",cs++,d);
	}
	return 0;
}