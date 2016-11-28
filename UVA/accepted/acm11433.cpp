#include<stdio.h>
#define M 100000007

long long i,j,s,n,k,dp[3][15050],dd;
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
			dp[i%2][j]=(2*dp[i%2][j-1]+dp[(i-1)%2][j-1])%M;

			if(j-2>=0)
				dp[i%2][j]=((dp[i%2][j]-dp[i%2][j-2])%M+M)%M;

			if(j-k-1>=0)
			{
				dd=(dp[(i-1)%2][j-k-1]*(k+1))%M;
				dp[i%2][j]=((dp[i%2][j]-dd)%M+M)%M;
			}

			if(j-k-2>=0)
			{
				dd=(dp[(i-1)%2][j-k-2]*k)%M;
				dp[i%2][j]=((dp[i%2][j]+dd)%M+M)%M;
			}
		}
	}
}

int main()
{
	while(scanf("%lld%lld",&n,&k) && (n>0 && k>0))
	{
		scanf("%lld",&s);

		call();

		printf("%lld\n",dp[n%2][s]%M);
	}
	return 0;
}
