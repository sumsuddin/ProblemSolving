#include<stdio.h>
long dp[100000],i,j,k,n,t,x[20],y[20],smux[20][20],cs=1;
long minv(long a,long b)
{
	return a>b?b:a;
}

long rec(long vs)
{
	if(vs==(1<<n)-1)
		return 0;
	if(dp[vs]>=0)
		return dp[vs];

	long i,j;
	dp[vs]=10000000;
	for(i=0;i<n;i++)
	{
		if(((vs>>i) & 1)==0)
		{
			for(j=i;j<n;j++)
				dp[vs]=minv(dp[vs],rec(vs|smux[i][j])+1);
			break;
		}
	}
	return dp[vs];
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&x[i],&y[i]);
			for(j=0;j<n;j++)
				smux[i][j]=0;
		}
		for(i=0;i<=(1<<n);i++)
			dp[i]=-1;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((x[i]-x[j]) * (y[i]-y[k]) == (x[i]-x[k]) * (y[i]-y[j]))
						smux[i][j] |= (1<<k);
		for(i=0;i<n;i++)
			smux[i][i]=0,smux[i][i]=1<<i;

		printf("Case %ld: %ld\n",cs++,rec(0));
	}
	return 0;
}