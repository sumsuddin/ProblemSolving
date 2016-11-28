#include<stdio.h>
long i,j,k,n,m,st[100][100],w,min,q,p,ans,sum,cs=1;
char sy[100][50];
long mini(long a,long b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	while(gets(sy[0]))
	{
		sscanf(sy[0],"%ld%ld",&n,&m);
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				st[i][j]=25000;
			st[i][i]=0;
			gets(sy[i]);
		}
		while(m--)
		{
			gets(sy[0]);
			sscanf(sy[0],"%ld%ld%ld",&p,&q,&w);
			st[p][q]=w;
			st[q][p]=w;
		}
		for(k=1;k<=n;k++)
			for(j=1;j<=n;j++)
				for(i=1;i<=n;i++)
					st[i][j]=mini(st[i][j],st[i][k]+st[k][j]);
		ans=1;
		min=25000;
		for(i=1;i<=n;i++)
		{
			sum=0;
			for(j=1;j<=n;j++)
				sum+=st[i][j];
			if(sum<min)
			{
				min=sum;
				ans=i;
			}
		}
		printf("Case #%ld : %s\n",cs++,sy[ans]);
	}
	return 0;
}