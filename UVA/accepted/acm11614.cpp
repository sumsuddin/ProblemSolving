#include<stdio.h>
#include<math.h>
long long n,x;
int main()
{
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&x);
		x=(long)sqrt(1+8*x);
		x=(x-1)/2;
		printf("%lld\n",x);
	}
	return 0;
}