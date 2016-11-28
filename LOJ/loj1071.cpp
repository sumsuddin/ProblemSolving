#include<stdio.h>

long mat[105][105],dp[105][105][105][2],t,n,m,i,j,k,cs=1;

long maxi(long a,long b)
{
	return a>b?a:b;
}

long rec(long r,long c1,long c2,long chk)
{
	if(r>=n || c1>=m || c2>=m || c1==c2)
		return 0;

	if(dp[r][c1][c2][chk]>=0)
		return dp[r][c1][c2][chk];

	long a,mx=0;

	if(chk && c1+1<c2)
	{
		a=rec(r,c1+1,c2,chk)+mat[r][c1];
		mx=maxi(mx,a);
	}

	a=rec(r,c1,c2+1,0)+mat[r][c2];
	mx=maxi(mx,a);

	if(r+1<n)
	{
		a=rec(r+1,c1,c2,1)+mat[r][c1]+mat[r][c2];
		mx=maxi(mx,a);
	}

	dp[r][c1][c2][chk]=mx;
	return dp[r][c1][c2][chk];
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				for(k=0;k<m;k++)
					dp[i][j][k][0]=dp[i][j][k][1]=-1;

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%ld",&mat[i][j]);

		dp[n-1][m-2][m-1][0]=dp[n-1][m-2][m-1][1]=mat[n-1][m-1]+mat[n-1][m-2];
		printf("Case %ld: %ld\n",cs++,rec(0,0,1,0));
	}
	return 0;
}