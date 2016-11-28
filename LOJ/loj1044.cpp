#include<stdio.h>
#include<string.h>
long i,j,dp[1005][1005],t,l,cs=1;
char st[1005];
int pel[1005][1005];
long min(long a,long b)
{
	return a<b?a:b;
}

int plin(long l,long h)
{
	if(pel[l][h]>=0)
		return pel[l][h];

	if(l==h)
		return pel[l][h]=1;

	if(l+1==h)
		return pel[l][h]= st[l]==st[h];
	else
		return pel[l][h]= st[l]==st[h] && plin(l+1,h-1);
}

long rec(long l,long h)
{
	if(dp[l][h]>=0)
		return dp[l][h];

	if(l==h)
		return dp[l][h]=1;

	if(plin(l,h))
		return dp[l][h]=1;

	dp[l][h]=1000000;

	long i;
	for(i=l;i<h;i++)
	{
		if(plin(l,i))
			dp[l][h]=min(dp[l][h],1+rec(i+1,h));
	}
	return dp[l][h];
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);

		l=strlen(st);

		for(i=0;i<l;i++)
			for(j=0;j<l;j++)
				dp[i][j]=pel[i][j]=-1;

		printf("Case %ld: %ld\n",cs++,rec(0,l-1));
	}
	return 0;
}