#include<stdio.h>

int main()
{
	long long n;

	while(scanf("%lld",&n)==1)
	{
		n=n/2+1;
		n*=n;

		n=n*2-1;
		n=3*n-6;
		printf("%lld\n",n);
	}
	return 0;
}