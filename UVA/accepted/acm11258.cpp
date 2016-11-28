#include<stdio.h>
#include<string.h>
#define inf 2147483647
long i,j,l,t;
char st[250];
long long dp[250][250];
long long mix(long long a,long long b)
{
	return a>b?a:b;
}

long long rec(long l,long h)
{
	if(l>h)
		return 0;
	else if(l==h)
		return st[l]-'0';

	if(dp[l][h]>=0)
		return dp[l][h];
	long i;

	long long sum=0;
	i=l;
	sum=0;

	long long mx=0;
	for(i=l;i<=h;i++)
	{
		if((sum*10+st[i]-'0')<=inf)
			sum=sum*10+st[i]-'0';
		else
			break;

		mx=mix(mx,sum+rec(i+1,h));
	}
	return dp[l][h]=mx;
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
				dp[i][j]=-1;

		printf("%lld\n",rec(0,l-1));
	}
	return 0;
}
