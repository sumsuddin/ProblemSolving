#include<stdio.h>
long t,n,m,a[20],i,sum,cs=1;
void rec(long len ,long ls)
{
	if(len==m)
	{
		sum++;
		return;
	}
	long i,d;
	for(i=0;i<n;i++)
	{
		d=ls-a[i];
		if(d<0)
			d*=-1;
		if(d<=2 || ls==-1)
			rec(len+1,a[i]);
	}
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		sum=0;
		rec(0,-1);
		
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}