#include<stdio.h>
#include<math.h>

long long i,sq,n,p,q,cs=1,sum;

int main()
{
	while(scanf("%lld",&n) && n)
	{
		sq=(long long)sqrt(n);
		sum=0;

		for(i=2;i<=sq;i++)
		{
			p=(long long)(n/i);
			q=(sq*(sq+1))/2;
			sum+=(p-1)*i + (p*(p+1))/2 - q;
		}
		printf("Case %lld: %lld\n",cs++,sum);
	}
	return 0;
}
