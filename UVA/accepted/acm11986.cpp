#include<stdio.h>
long long n,ans , t,cs=1;
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		n++;

		while(n>1)
		{
			n=n-(n/2);
			ans++;
		}

		printf("Case %lld: %lld\n",cs++,ans);
	}
	return 0;
}
