#include<stdio.h>
typedef long long lng;
lng a,b,n,d,l;

lng gcd(lng a,lng b)
{
	lng c=a%b;
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
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld",&a,&b);
		if(b%a==0 && b>=a)
		{
			d=b/a;
			l=gcd(d,a);
			l=(d*a)/l;
			while(l<b)
			{
				l=gcd(d,a);
				l=(d*a)/l;
				d*=(b/l);
			}
			printf("%lld\n",d);
		}
		else
			printf("NO SOLUTION\n");
	}
	return 0;
}