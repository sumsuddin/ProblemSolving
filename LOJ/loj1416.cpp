#include<stdio.h>
#include<string.h>

char st[105],sy[105],sr[305];
long dp[105][105][305],i,j,k,t,l1,l2,l3;

long call(long l1,long l2,long l3)
{
	if(l1<0 || l2<0 || l3<0)
		return 0;

	if(dp[l1][l2][l3]>=0)
		return dp[l1][l2][l3];

	dp[l1][l2][l3]=0;

	if(st[l1]==sy[l2] && sy[l2]==sr[l3])
		return call(l1-1,l2-1,l3-1);

	return call(l1-1,l2,l3)+call(l1,l2-1,l3)+call(l1,l2,l3-1)-2*call(l1-1,l2-1,l3-1);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%s%s",st,sy,sr);

		l1=strlen(st);
		l2=strlen(sy);
		l3=strlen(sr);

		for(i=0;i<l1;i++)
			for(j=0;j<l2;j++)
				for(k=0;k<l3;k++)
					dp[i][j][k]=-1;
		dp[0][0][0]=1;

		printf("%ld\n",call(l1-1,l2-1,l3-1));

	}
	return 0;
}