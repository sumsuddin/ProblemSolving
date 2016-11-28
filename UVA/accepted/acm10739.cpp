#include<stdio.h>
#include<string.h>
long cs=1,dp[1050][1050],t,i,j;
char st[1050];

long minv(long a,long b)
{
	return a>b?b:a;
}

long rec(long l,long h)
{
	if(l==h)
		return dp[l][h]=0;
	else if(l+1==h)
	{
		if(st[l]==st[h])
			return dp[l][h]=0;
		else
			return dp[l][h]=1;
	}
	if(dp[l][h]>=0)
		return dp[l][h];

	if(st[l]==st[h])
		return dp[l][h]=rec(l+1,h-1);
	else
	{
		long a=rec(l,h-1);
		a=minv(a,rec(l+1,h));
		a=minv(a,rec(l+1,h-1));
		return dp[l][h]=a+1;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);

		for(i=0;st[i];i++)
			for(j=0;st[j];j++)
				dp[i][j]=-1;

		printf("Case %ld: %ld\n",cs++,rec(0,strlen(st)-1));
	}
	return 0;
}