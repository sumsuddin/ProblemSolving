#include<stdio.h>
long a[20],i,c,t,n,sum,ml,gc,cs=1;

long gcd(long a,long b)
{
	while(1)
	{
		c=b%a;
		if(c==0)
			break;
		b=a;
		a=c;
	}
	return a;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		ml=1;sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			ml*=a[i];
		}
		for(i=0;i<n;i++)
			sum+=ml/a[i];

		ml*=n;
		gc=gcd(ml,sum);

		printf("Case %ld: %ld/%ld\n",cs++,ml/gc,sum/
			gc);
	}
	return 0;
}