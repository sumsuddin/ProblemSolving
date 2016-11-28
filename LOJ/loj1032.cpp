#include<stdio.h>
long t,cs=1;
long long n;
long long rec(long long n)
{
	if(n<3)
		return 0;
	if(n<5)
		return 1;

	long long d=1,p;
	long i=0;

	while(d*2<=n)
		d*=2,i++;
	p=(n-d+1)-d/2;
	if(p<0)
		p=0;
	p+=(d/4)*(i-1);
	return rec(n-d)+p;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%lld",&n);

		printf("Case %ld: %lld\n",cs++,rec(n));
	}
	return 0;
}
