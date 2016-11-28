#include<stdio.h>
long long j,n;
int main()
{
	while(scanf("%lld",&n) && n)
	{
		j=n/9;
		if(n%9==0)
			printf("%lld %lld\n",n+j-1,n+j);
		else
			printf("%lld\n",n+j);
	}
	return 0;
}
