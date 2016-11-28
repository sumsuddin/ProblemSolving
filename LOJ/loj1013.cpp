#include<stdio.h>
#include<string.h>
long dp[50][50],ans[50][50],t,l1,l2,i,j,cs=1;

char st[50],sy[50],path[50][50];

long len(long l1 ,long l2)
{
	if(l1<0)
		return l2;
	if(l2<0)
		return l1;
	if(dp[l1][l2]>=0)
		return dp[l1][l2];

	if(st[l1]==sy[l2])
		return dp[l1][l2]=len(l1-1,l2-1)+1;
	else
	{
		long a=len(l1-1,l2)+1,b=len(l1,l2-1)+1;
		
		if(a==b)
		{
			path[l1][l2]='x';
			return dp[l1][l2]=a;
		}
		if(a<b)
		{
			path[l1][l2]='u';
			return dp[l1][l2]=a;
		}
		else
		{
			path[l1][l2]='l';
			return dp[l1][l2]=b;
		}
	}
}

long way(long l1,long l2)
{
	if(l1<0 || l2<0)
		return 1;
	if(ans[l1][l2]>=0)
		return ans[l1][l2];

	if(st[l1]==sy[l2])
		return ans[l1][l2]=way(l1-1,l2-1);
	if(path[l1][l2]=='x')
		return ans[l1][l2]=way(l1-1,l2)+way(l1,l2-1);
	if(path[l1][l2]=='u')
		return ans[l1][l2]=way(l1-1,l2);
	else
		return ans[l1][l2]=way(l1,l2-1);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%s",st,sy);

		l1=strlen(st);
		l2=strlen(sy);

		for(i=0;i<l1;i++)
			for(j=0;j<l2;j++)
				dp[i][j]=ans[i][j]=-1;

		printf("Case %ld: %ld",cs++,len(l1-1,l2-1)+1);

		printf(" %ld\n",way(l1-1,l2-1));
	}
	return 0;
}