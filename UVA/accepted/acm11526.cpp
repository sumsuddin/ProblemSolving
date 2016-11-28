#include<stdio.h>
#include<math.h>
long long i,a,b,t,sum,sq,prv;
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		sum=0;
		scanf("%lld",&a);
		sq=(long long)sqrt(a);

		prv=0;
		for(i=1;i<=sq;i++)
		{
			b=a/i;
			sum+=b;
			sum+=(prv-b)*(i-1);
			prv=b;
		}
		sum+=(prv-sq)*sq;
		printf("%lld\n",sum);
	}
	return 0;
}
