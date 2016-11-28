#include<stdio.h>
#define MAX 110000
long p,q,st[110][110],t,n,i,j,k,m,start,des,cs=1;
long min(long a,long b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
					st[i][j]=MAX;
			st[i][i]=0;
		}
		while(m--)
		{
			scanf("%ld%ld",&p,&q);
			st[p][q]=1;
			st[q][p]=1;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					st[i][j]=min(st[i][j],st[i][k]+st[k][j]);
			}
		}
		m=0;
		scanf("%ld%ld",&start,&des);
		for(i=0;i<n;i++)
		{
			if(st[start][i]+st[i][des]>m)
				m=st[start][i]+st[i][des];
		}
		printf("Case %ld: %ld\n",cs++,m);
	}
	return 0;
}