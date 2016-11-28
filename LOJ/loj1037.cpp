#include<stdio.h>

long i,j,t,n,hl[20],dp[20][70000],ok,cs=1;
char atk[20][20];
long minv(long a,long b)
{
	return a>b?b:a;
}

long rec(long vs,long crnt)
{
	if(vs==ok)
		return hl[crnt];
	if(crnt!=-1 && dp[crnt][vs]>=0)
		return dp[crnt][vs];

	long mn,mx;
	mn=100000000;
	long i;
	for(i=0;i<n;i++)
	{
		if(((vs>>i) & 1)==0)
		{
			mx=1;
			for(j=0;j<n;j++)
				if(((vs>>j) & 1)==0 && j!=crnt)
					if(atk[j][crnt]-'0'>mx)
						mx=atk[j][crnt]-'0';

			long d;
			if(crnt==-1)
				d=0;
			else
			{
				d=hl[crnt]/mx;
				if(hl[crnt]%mx)
					d++;
			}

			mn=minv(mn,rec(vs | (1<<i),i)+d);
		}
	}
	if(crnt==-1)
		return mn;
	else
		return dp[crnt][vs]=mn;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		ok=(1<<n)-1;

		for(i=0;i<n;i++)
			for(j=0;j<=ok;j++)
				dp[i][j]=-1;

		for(i=0;i<n;i++)
			scanf("%ld",&hl[i]);

		for(i=0;i<n;i++)
			scanf("%s",atk[i]);

		printf("Case %ld: %ld\n",cs++,rec(0,-1));
	}
	return 0;
}