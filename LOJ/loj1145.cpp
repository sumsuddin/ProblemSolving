#include<stdio.h>
long cs=1,dp[3][15050],s,k,n,i,j,t;
void call()
{
	for(i=0;i<=s;i++)
		dp[0][i]=0;
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=s;j++)
			dp[i%2][j]=0;

		for(j=1;j<=s;j++)
		{
			dp[i%2][j]=(dp[i%2][j-1]+dp[(i-1)%2][j-1])%100000007;
			if(j-k-1>=0)
			{
				dp[i%2][j]=(dp[i%2][j]-dp[(i-1)%2][j-k-1])%100000007;
				if(dp[i%2][j]<0)
					dp[i%2][j]+=100000007;
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&n,&k,&s);

		call();
		printf("Case %ld: %ld\n",cs++,dp[n%2][s]%100000007);
	}
	return 0;
}