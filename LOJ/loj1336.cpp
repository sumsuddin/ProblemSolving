#include<stdio.h>
#include<math.h>

long long n,ans,cs=1,t;

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);

		ans=(long long)sqrt(n)+(long long)sqrt(n/2);

		printf("Case %lld: %lld\n",cs++,n-ans);
	}
	return 0;
}