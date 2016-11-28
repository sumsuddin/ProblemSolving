#include<stdio.h>
#include<math.h>

long long n,ans;

int main()
{
	while(~scanf("%lld",&n) && n)
	{
		ans=(long long)sqrt(n)+(long long)sqrt(n/2);

		printf("%lld\n",n-ans);
	}
	return 0;
}
