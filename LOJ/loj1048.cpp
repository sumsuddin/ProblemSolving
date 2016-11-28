#include<stdio.h>
long a[1050],i,n,m,sum,cs=1,t,mid,j;
bool chk(long p,long trn)
{
	long i,sum=0;
	for(i=0;i<=n;i++)
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
	long h,l;
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
		m++;
		for(i=0;i<=n;i++)
			scanf("%ld",&a[i]),sum+=a[i];

		mid=bsc();
		printf("Case %ld: %ld\n",cs++,mid);

		for(i=m-1,j=0;i>=0;i--)
		{
			sum=0;
			while(sum+a[j]<=mid && j<=n-i)
				sum+=a[j++];
			printf("%ld\n",sum);
		}
	}
	return 0;
}