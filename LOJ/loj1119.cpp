#include<stdio.h>
long i,j,mat[20][20],dp[100000],n,t,cs=1;

long minv(long a,long b)
{
	return a<b?a:b;
}

long rec(long vs)
{
	if(dp[vs]>=0)
		return dp[vs];

	if(vs==(1<<n)-1)
		return dp[vs]=0;

	long i,j,mn=100000000;

	for(i=0;i<n;i++)
	{
		if(((vs>>i) & 1)==0)
		{
			long cst=0;

			for(j=0;j<n;j++)
			{
				if(((vs>>j) & 1))
					cst+=mat[i][j];
			}

			mn=minv(mn,rec(vs | (1<<i))+cst+mat[i][i]);
		}
	}
	return dp[vs]=mn;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<(1<<n);i++)
			dp[i]=-1;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%ld",&mat[i][j]);

		printf("Case %ld: %ld\n",cs++,rec(0));
	}
	return 0;
}