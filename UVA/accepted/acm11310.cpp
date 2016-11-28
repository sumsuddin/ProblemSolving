#include<stdio.h>
long long t,n,dp[50][50],i,j;
long long rec(long long a,long long b)
{
	if(a<0 || b<0 || (a==0 && b==0))
		return 0;
	if(dp[a][b]>=0)
		return dp[a][b];
	if((a==1 && b==0) || (a==0 && b==1) || (a==1 && b==1))
		return dp[a][b]=1;
	long long ret;

	if(a==2 && b==1)
		ret=1;
	else
		ret=0;

	if(a==b)
		ret+=2*rec(a,b-1)+2*rec(a-1,b-2)-rec(a-1,b-1);
	else
		ret+=rec(a-1,b)+rec(a-2,b-1);

	return dp[a][b]=ret;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);

		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=-1;

		printf("%lld\n",rec(n,n));
	}
	return 0;
}