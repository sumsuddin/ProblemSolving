#include<stdio.h>
#include<math.h>
long t,n,c,cs=1;
double ans;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&c);

		if(n==0)
			ans=0;
		else
			ans=(double)c/(2.0*(double)n);

		if(c<=n)
			c=0;
		else
			c=(long)ans;

		ans-=c;
		if(ans>0.5)
			c++;

		printf("Case %ld: %ld\n",cs++,c);
	}
	return 0;
}
