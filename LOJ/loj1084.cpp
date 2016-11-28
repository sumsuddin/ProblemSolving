#include<stdio.h>
#include<algorithm>
#define inf 10000000
using namespace std;
long dp[200000],loc[200000],t,n,i,flag,d,k,x,cs=1;

long bsearch(long vlu,long h)
{
	long l=0,mid;
	while(l<h)
	{
		mid=(l+h)/2;

		if(mid-1>=0 && loc[mid-1]>=vlu)
			h=mid-1;
		if(loc[mid]>=vlu)
			h=mid;
		else
			l=mid+1;
	}
	return h;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&k);

		for(i=1;i<=n;i++)
			scanf("%ld",&loc[i]);

		sort(loc+1,loc+n+1);
		loc[0]=0;

		for(i=0;i<=n;i++)
		dp[i]=inf;

		dp[0]=0;
		flag=1;
		x=0;
		for(i=1;i<=n && flag;i++)
		{
			d=bsearch(loc[i]-2*k,i-1);

			if(d && i-d>=2)
			dp[i]=min(dp[i],dp[d-1]+1);
			d++;
			if(i-d>=2)
			dp[i]=min(dp[i],dp[d-1]+1);
			d++;
			if(i-d>=2)
			dp[i]=min(dp[i],dp[d-1]+1);
			d++;
			if(i-d>=2)
			dp[i]=min(dp[i],dp[d-1]+1);


			if(dp[i]>=10000000)
			{
			    x++;

			    if(x>2)
			    flag=0;
			}
			else
			x=0;
		}
		if(flag && dp[n]<10000000)
		printf("Case %ld: %ld\n",cs++,dp[n]);
		else
		printf("Case %ld: -1\n",cs++);
	}
	return 0;
}
