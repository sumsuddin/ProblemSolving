#include<stdio.h>
long dp[205][25][15],i,d,r,q,n,a[205],cs=1,ccs;
long rec(long ind,long sum,long rem)
{
	if(rem==0)
		return !(((sum%d)+d)%d);

	if(ind>=n)
		return 0;

	if(dp[ind][sum][rem]>=0)
		return dp[ind][sum][rem];

	long ret=0;
	ret=rec(ind+1,(((sum+a[ind])%d)+d)%d,rem-1);
	ret+=rec(ind+1,sum,rem);

	dp[ind][sum][rem]=ret;
	return dp[ind][sum][rem];
}

int main()
{
	while(scanf("%ld%ld",&n,&q) && (n || q))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		printf("SET %ld:\n",cs++);
		ccs=1;
		while(q--)
		{
			for(i=0;i<=n;i++)
				for(d=0;d<=25;d++)
					for(r=0;r<=10;r++)
						dp[i][d][r]=-1;

			scanf("%ld%ld",&d,&r);

			printf("QUERY %ld: %ld\n",ccs++,rec(0,0,r));
		}
	}
	return 0;
}
