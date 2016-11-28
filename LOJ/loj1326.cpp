#include<stdio.h>
long cs,dp[1006],ncr[1005][1005],fac[1005],i,t,n,j,x,y;

long call(long a,long b)
{
	if(b>a)
		return ncr[a][b]=0;

	if(b==1 && a>=b)
		return ncr[a][b]=a%10056;

	if(ncr[a][b]>-1)
		return ncr[a][b];

	return ncr[a][b]=(call(a-1,b)+call(a-1,b-1))%10056;
}

int main()
{
	n=1001;
	fac[0]=1;
	for(i=1;i<n;i++)
		fac[i]=(fac[i-1]*i)%10056;

	for(i=0;i<1001;i++)
		for(j=0;j<1001;j++)
			ncr[i][j]=-1;

	call(1000,1000);

	dp[1]=1;
	for(i=2;i<n;i++)
	{
		dp[i]=1;
		for(j=1;j<i;j++)
			dp[i]=(dp[i]+(dp[i-j]*call(i,j))%10056)%10056;
	}


	cs=1;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		printf("Case %ld: %ld\n",cs++,dp[n]);
	}
	return 0;
}