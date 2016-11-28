#include<stdio.h>
long i,n,t,a[1005],b[1005],c[1005],d[1005],cs=1;
long min(long a,long b)
{
	return a>b?b:a;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&b[i]);

		for(i=1;i<n;i++)
			scanf("%ld",&c[i]);
		for(i=1;i<n;i++)
			scanf("%ld",&d[i]);
		for(i=1;i<n;i++)
		{
			a[i]=min(a[i]+a[i-1],a[i]+b[i-1]+d[i]);

			b[i]=min(b[i]+b[i-1],b[i]+a[i-1]+c[i]);
		}
		printf("Case %ld: %ld\n",cs++,min(a[n-1],b[n-1]));
	}
	return 0;
}