#include<stdio.h>
#include<string.h>
char st[1005],sy[1005],path[1005][1005];
long lc[1005][1005],ans[1005][1005],i,j,cs=1,t;

long lcs(long l1,long l2)
{
	if(l1<0 || l2<0)
		return 0;

	if(lc[l1][l2]>=0)
		return lc[l1][l2];

	if(st[l1]==sy[l2])
	{
		path[l1][l2]='c';
		return lc[l1][l2]=lcs(l1-1,l2-1)+1;
	}
	else
	{
		long p,q;
		p=lcs(l1-1,l2);
		q=lcs(l1,l2-1);
		if(p>q)
			path[l1][l2]='u';
		else if(p<q)
			path[l1][l2]='l';
		else
			path[l1][l2]='x';

		return lc[l1][l2]=p>q?p:q;
	}
}

long rec(long l1,long l2)
{
	if(l1<0 || l2<0)
		return 0;

	if(ans[l1][l2]>=0)
		return ans[l1][l2];

	if(st[l1]==sy[l2] && lc[l1][l2]==1)
		return ans[l1][l2]=1;

	if(path[l1][l2]=='c')
		return ans[l1][l2]=rec(l1-1,l2-1)%1000007;
	
	if(path[l1][l2]=='u')
		return ans[l1][l2]=rec(l1-1,l2)%1000007;

	if(path[l1][l2]=='l')
		return ans[l1][l2]=rec(l1,l2-1)%1000007;

	long d;

	if(lc[l1-1][l2-1]==lc[l1-1][l2])
		d=rec(l1-1,l2-1)%1000007;
	else
		d=0;
	return ans[l1][l2]=((rec(l1,l2-1)+rec(l1-1,l2)-d)%1000007+1000007)%1000007;
}


int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%s",st,sy);

		for(i=0;st[i];i++)
			for(j=0;sy[j];j++)
				lc[i][j]=ans[i][j]=-1;

		i=strlen(st)-1;
		j=strlen(sy)-1;
		lcs(i,j);
		i=rec(i,j);
		if(i==0)
			i=1;
		printf("Case %ld: %ld\n",cs++,((i%1000007)+1000007)%1000007);
	}
	return 0;
}