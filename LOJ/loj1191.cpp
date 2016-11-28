#include<stdio.h>

long long dp[55][55][55],n,m,mx,t,i,j,cs=1;

long long call(long long n,long long m,long long mx)
{
	if(n<m)
		return dp[n][m][mx]=0;
	if(m==1)
	{
		if(n<=mx)
			return dp[n][m][mx]=1;
		else
			return dp[n][m][mx]=0;
	}


	if(dp[n][m][mx]>-1)
		return dp[n][m][mx];

	dp[n][m][mx]=0;
	for(long long i=1;i<=mx && n-i>0;i++)
		dp[n][m][mx]+=call(n-i,m-1,mx);

	return dp[n][m][mx];
}

int main()
{
	for(i=0;i<51;i++)
		for(j=0;j<51;j++)
			for(t=0;t<51;t++)
				dp[i][j][t]=-1;

	for(i=1;i<=50;i++)
		call(50,10,i);

	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&mx);

		printf("Case %lld: %lld\n",cs++,call(n,m,mx));
	}
	return 0;
}
