#include<stdio.h>
#include<math.h>

long long i,sq,n,p,q,t,cs=1,sum;

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);

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