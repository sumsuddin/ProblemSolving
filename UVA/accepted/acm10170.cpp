#include<stdio.h>
long long n,sum,d;
int main()
{
	while(scanf("%lld%lld",&n,&d)==2)
	{
		for(sum=n;sum<d;sum+=++n)
			;
		printf("%lld\n",n);
	}
	return 0;
}