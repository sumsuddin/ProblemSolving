#include<stdio.h>
long i,j,n,t,mat[100][100],rm[1000000],l,cs=1;
long rec(long r,long vst)
{
	long mx=0,i,s;
	if(rm[vst]!=-1)
		return rm[vst];
	for(i=0;i<n;i++)
	{
		s=0;
		if(((vst>>i) & 1)==0)
		{
			if(r==n-1)
				s=mat[r][i];
			else
				if(rm[vst]==-1)
					s=mat[r][i]+rec(r+1,vst | (1<<i));
				else
					s=rm[vst];
		}
		if(mx<s)
			mx=s;
	}
	return rm[vst]=mx;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		l=0;
		for(i=0;i<n;i++)
		{
			l|=1<<i;

			for(j=0;j<n;j++)
				scanf("%ld",&mat[i][j]);
		}

		for(i=0;i<=l;i++)
			rm[i]=-1;

		printf("Case %ld: %ld\n",cs++,rec(0,0));
	}
	return 0;
}