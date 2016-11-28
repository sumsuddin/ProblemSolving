#include<stdio.h>
long long M=1000000007,i,ans,t,k,p,dp[505][505],lst,prm[600],j,cs=1;
bool bu[3700];
long long rec(long long lvl,long long tot)
{
	if(lvl==0)
		return dp[lvl][tot]=1;

	if(dp[lvl][tot]>=0)
		return dp[lvl][tot];
	
	long long i,x=0;
	
	for(i=1;i<=tot;i++)
		x=(x+(prm[i]*rec(lvl-1,i))%M)%M;
	
	return dp[lvl][tot]=x;
}

int main()
{
	scanf("%lld",&t);

	lst=1;
	prm[lst++]=2;
	for(i=3;i<3600;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<3600;j+=i*2)
				bu[j]=1;
		}
	}
	for(i=0;i<505;i++)
		for(j=0;j<505;j++)
			dp[i][j]=-1;

	while(t--)
	{
		scanf("%lld%lld",&k,&p);

		ans=1;
		for(i=1;i<=p;i++)
			ans=(ans*(prm[i]-1))%M;

		ans=(ans*rec(k-p,p))%M;

		printf("Case %lld: %lld\n",cs++,ans);
	}
	return 0;
}
