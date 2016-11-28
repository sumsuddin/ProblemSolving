#include<stdio.h>
#include<string.h>
long dp[110][110][110],t,i,j,k,l,cs=1;
char st[110],sy[110];
long rec(long a,long b,long n)
{
	if(a<0 || b<0)
		return 10000000;

	if(n<0)
	{
		if(a==0 && b==0)
			return 0;
		else
			return 10000000;
	}

	if(dp[a][b][n]>=0)
		return dp[a][b][n];


	long p,q;
	if(st[n]=='0')
	{
		if(sy[n]==st[n])
		{
			p=rec(a,b,n-1);

			q=rec(a-1,b,n-1);

			if(q<p)
				p=q;

			q=rec(a,b+1,n-1)+1;

			if(q<p)
				p=q;

			return dp[a][b][n]=p;
		}
		else
		{
			p=rec(a,b-1,n-1);
			q=rec(a+1,b,n-1)+1;

			if(q<p)
				p=q;

			q=rec(a,b,n-1)+1;

			if(q<p)
				p=q;

			return dp[a][b][n]=p;
		}
	}
	else if(st[n]=='1')
	{
		if(sy[n]=='0')
		{
			p=rec(a-1,b,n-1);

			q=rec(a,b+1,n-1)+1;

			if(q<p)
				p=q;

			return dp[a][b][n]=p;
		}
		else
		{
			return dp[a][b][n]=rec(a,b,n-1);
		}
	}
	else
	{
		if(sy[n]=='0')
		{
			p=rec(a,b,n-1)+1;

			q=rec(a-1,b,n-1)+1;

			if(q<p)
				p=q;

			q=rec(a,b+1,n-1)+2;

			if(q<p)
				p=q;

			return dp[a][b][n]=p;
		}
		else
		{
			p=rec(a,b,n-1)+1;

			q=rec(a,b-1,n-1)+1;

			if(q<p)
				p=q;

			q=rec(a+1,b,n-1)+2;

			if(q<p)
				p=q;

			return dp[a][b][n]=p;
		}
	}

}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%s",&st,&sy);

		l=strlen(st);

		for(i=0;i<l;i++)
			for(j=0;j<l;j++)
				for(k=0;k<l;k++)
					dp[i][j][k]=-1;

		i=rec(0,0,l-1);
		if(i>=10000000)
			i=-1;

		printf("Case %ld: %ld\n",cs++,i);
	}
	return 0;
}

