#include<stdio.h>
long long i,fn,n,sum,t,d;
long long fact(long long a)
{
	if(a==0)
		return 1;
	else
		return a*fact(a-1);
}
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);

		fn=fact(n);
		sum=0;d=1;
		for(i=0;i<=n;i++,d*=-1)
			sum+=(d*(fn/fact(i)));

		printf("%lld/%lld\n",sum,fn);
	}
	return 0;
}