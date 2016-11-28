#include<stdio.h>
long a,i,t,n,m,dp[505][505],vst[505][505],cs,j,comu[505][505],comr[505][505];
long rec(long n,long m)
{
	if(n <0 || m <0)
	return 0;
	
	if(vst[n][m]==cs)
	return dp[n][m];
	
	vst[n][m]=cs;
	
	long a=rec(n-1,m)+comu[n][m];
	long b=rec(n,m-1)+comr[n][m];
	dp[n][m]=a>b?a:b;
	
	return dp[n][m];
}

int main()
{
	scanf("%ld",&t);
	
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		cs++;
		
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%ld",&a);
			if(j==0)
			comu[i][j]=a;
			else
			comu[i][j]=comu[i][j-1]+a;
		}
		
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%ld",&a);
			if(i==0)
			comr[i][j]=a;
			else
			comr[i][j]=comr[i-1][j]+a;
		}
		
		printf("Case %ld: %ld\n",cs,rec(n-1,m-1));
	}
	return 0;
}
