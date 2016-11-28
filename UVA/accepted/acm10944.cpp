#include<stdio.h>

struct ss
{
	long x,y;
}
start,gold[16];

long min(long a,long b)
{
	return a>b?b:a;
}

long dp[16][1<<16],r,c,i,j,lst,ans,x,y;
char st[20][20];
long dist(ss a,ss b)
{
	x= (a.x<b.x?-a.x+b.x:a.x-b.x);y=((a.y>b.y)?a.y-b.y:b.y-a.y);

	return x>y?x:y;
}
long rec(long tj,long vs)
{
	if(vs==(1<<lst)-1)
		return dist(gold[tj],start);

	if(dp[tj][vs]>=0)
		return dp[tj][vs];

	dp[tj][vs]=1000000;
	for(long i=0;i<lst;i++)
		if(((vs>>i) &1)==0)
			dp[tj][vs]=min(dp[tj][vs],rec(i,vs | (1<<i))+dist(gold[tj],gold[i]));
	return dp[tj][vs];
}

int main()
{
	while(~scanf("%ld%ld",&r,&c))
	{
		lst=0;

		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		for(i=0;i<r;i++)
			for(j=0;st[i][j];j++)
				if(st[i][j]=='L')
					start.x=i,start.y=j;
				else if(st[i][j]=='#')
					gold[lst].x=i,gold[lst++].y=j;

		for(i=0;i<lst;i++)
			for(j=0;j<(1<<lst);j++)
				dp[i][j]=-1;

		if(lst==0)
			ans=0;
		else
			ans=1000000;

		for(i=0;i<lst;i++)
			ans=min(ans,rec(i,1<<i)+dist(start,gold[i]));
		printf("%ld\n",ans);
	}
	return 0;
}
