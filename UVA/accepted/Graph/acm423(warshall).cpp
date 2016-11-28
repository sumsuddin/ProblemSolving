#include<stdio.h>

long i,j,n,st[120][120],w,k,sum;
char sy[20];

long min(long a,long b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				st[i][j]=1000000000;

		for(i=2;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				scanf("%s",sy);
				if(sy[0]=='x')
					w=1000000000;
				else
					sscanf(sy,"%ld",&w);

				st[i][j]=w;
				st[j][i]=w;
			}
			st[i][i]=0;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					st[i][j]=min(st[i][j],st[i][k]+st[k][j]);
				}
			}
		}
		sum=-1;
		for(i=2;i<=n;i++)
			if(sum<st[1][i])
				sum=st[1][i];
		printf("%ld\n",sum);
	}
	return 0;
}