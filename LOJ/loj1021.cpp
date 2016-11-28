#include<stdio.h>
#include<string.h>

long long dp[21][70000],i,j,k,b,t,cs=1,l,end;
char st[25];

long long rec(long long m,long long vs)
{
	if(dp[m][vs]>=0)
		return dp[m][vs];
	if(vs==end)
		return dp[m][vs]=!(m%k);

	long long i;
	dp[m][vs]=0;
	for(i=0;i<l;i++)
	{
		if( ((vs>>i) & 1)==0 )
			dp[m][vs]+=rec( ( m*b+st[i] )%k ,vs | (1<<i));
	}
	return dp[m][vs];
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%s",&b,&k,st);

		l=strlen(st);

		if(st[0]=='-')
		{
			for(i=1;i<=l;i++)
				st[i-1]=st[i];
			l--;
		}
		for(i=0;st[i];i++)
			if(st[i]<='9')
				st[i]-='0';
			else
				st[i]-=('A'-10);

		end=(1<<l)-1;

		for(i=0;i<k;i++)
			for(j=0;j<=end;j++)
				dp[i][j]=-1;

		printf("Case %lld: %lld\n",cs++,rec(0,0));
	}
	return 0;
}
