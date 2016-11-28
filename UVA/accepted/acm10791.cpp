#include<stdio.h>
#include<math.h>
long long i,n,sum,sq,cs=1,stk,tst;
int main()
{
	while(scanf("%lld",&n) && n)
	{
		if(n==1)
		{
			printf("Case %lld: %lld\n",cs++,2);
			continue;
		}
		stk=n;
		sum=0;
		tst=1;
		while(n%2==0)
		{
			tst*=2;
			n/=2;
		}
		if(tst>1)
			sum=tst;

		sq=sqrt(n);

		i=3;
		while(n>1 && i<=sq)
		{
			tst=1;
			while(n%i==0)
			{
				tst*=i;
				n/=i;
			}
			if(tst>1)
				sum+=tst;
			i+=2;
		}
		if(n>1)
			sum+=n;
		if(sum==stk)
			printf("Case %lld: %lld\n",cs++,stk+1);
		else
			printf("Case %lld: %lld\n",cs++,sum);
	}
	return 0;
}