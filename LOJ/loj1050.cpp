#include<stdio.h>

long cs=1,t,r,b,i,j;
double dp[505][505][3];

double rec(long r,long b,long who)
{
	if(dp[r][b][who]>-1.0)
		return dp[r][b][who];

	if(b>=1 && r==0)
		return dp[r][b][who]=1.0;

	if(b==0 || r==0)
		return dp[r][b][who]=0.0;

	if(who)
		return dp[r][b][who]=rec(r,b-1,!who);
	else
		return dp[r][b][who]=rec(r,b-1,!who)*((double)b/(double)(r+b))+rec(r-1,b,!who)*((double)r/(double)(r+b));
}

int main()
{
	scanf("%ld",&t);

	for(i=0;i<=500;i++)
		for(j=0;j<=500;j++)
			dp[i][j][0]=dp[i][j][1]=-5.0;

	for(i=500;i>=0;i--)
		rec(i,500,0),rec(500,i,1);

	while(t--)
	{
		scanf("%ld%ld",&r,&b);

		printf("Case %ld: %.10lf\n",cs++,rec(r,b,0)+1e-11);
	}
	return 0;
}