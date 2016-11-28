#include<stdio.h>
long a[1050],i,n,m,sum,cs=1,t;
bool chk(long p,long trn)
{
	long i,sum=0;
	for(i=0;i<n;i++)
		if(sum+a[i]<=p)
			sum+=a[i];
		else
		{
			if(trn==1 || a[i]>p)
				return 0;
			sum=a[i],trn--;
		}
	return 1;
}
long bsc()
{
	long h,l,mid;
	l=0;h=sum;

	while(l<h)
	{
		mid=(l+h)/2;
		if(chk(mid,m))
			h=mid;
		else
			l=mid+1;
	}
	return (l+h)/2;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		sum=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]),sum+=a[i];

		printf("Case %ld: %ld\n",cs++,bsc());
	}
	return 0;
}