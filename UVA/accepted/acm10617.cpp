#include<stdio.h>
#include<string.h>
long long dp[70][70][5],i,j,l,t;
char st[70];
long long rec(long long l,long long h,long long x)
{
	if(l>h)
		return x;

	if(dp[l][h][x]>=0)
		return dp[l][h][x];

	long long ret=0;
	if(st[l]==st[h])
		ret+=rec(l+1,h-1,1);

	ret+=rec(l+1,h,x);

	ret+=rec(l,h-1,x);

	ret-=rec(l+1,h-1,x);

	return dp[l][h][x]=ret;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%s",st);
		l=strlen(st);

		for(i=0;i<l;i++)
			for(j=0;j<l;j++)
				dp[i][j][0]=dp[i][j][1]=-1;

		printf("%lld\n",rec(0,l-1,0));
	}
	return 0;
}