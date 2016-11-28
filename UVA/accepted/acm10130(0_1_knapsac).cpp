#include<stdio.h>
long i,j,sum,dp[50],wt[1050],pf[1050],t,n;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<31;i++)
			dp[i]=0;

		for(i=0;i<n;i++)
			scanf("%ld%ld",&pf[i],&wt[i]);

		for(i=0;i<n;i++)
		{
			for(j=31;j>0;j--)
			{
				if(j>=wt[i] && dp[j]<dp[j-wt[i]]+pf[i])
					dp[j]=dp[j-wt[i]]+pf[i];
			}
		}
		scanf("%ld",&n);
		sum=0;
		while(n--)
		{
			scanf("%ld",&pf[0]);
			sum+=dp[pf[0]];
		}
		printf("%ld\n",sum);
	}
	return 0;
}