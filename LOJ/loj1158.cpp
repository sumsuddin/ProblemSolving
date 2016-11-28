#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long l,i,j,end,dp[1001][2000],t,d,cs=1;
char st[15];
long long rec(long long md,long long vs)
{
	if(dp[md][vs]>=0)
		return dp[md][vs];

	if(vs==end)
		return dp[md][vs]=!(md%d);

	dp[md][vs]=0;
	long long i;
	char s=-1;
	for(i=0;st[i];i++)
		if(s!=st[i] && ((vs>>i) & 1)==0)
			s=st[i],dp[md][vs]+=rec((md*10+(st[i]-'0'))%d , vs | (1<<i));

	return dp[md][vs];
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%s%lld",st,&d);

		l=strlen(st);

		end=(1<<l)-1;

		for(i=0;i<d;i++)
			for(j=0;j<=end;j++)
				dp[i][j]=-1;

		sort(st,st+l);

		printf("Case %lld: %lld\n",cs++,rec(0,0));
	}
	return 0;
}
