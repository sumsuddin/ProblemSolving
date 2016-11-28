#include<stdio.h>
long long n,k,t,cs=1;
long long rec(long long n,long long k)
{
	if(n==1)
		return 0;
	return (rec(n-1,k)+k)%n;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&k);

		if(n==1)
			printf("Case %lld: %lld\n",cs++,1);
		else
			printf("Case %lld: %lld\n",cs++,(rec(n-1,k)+k)%n+1);
	}
	return 0;
}