#include<stdio.h>
long i,j,n,m,x,y,ls,mx,cst[120],t,ans,cs=1;
bool mat[120][120];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=0;

		for(i=0;i<n;i++)
			scanf("%ld",&cst[i]);

		while(m--)
		{
			scanf("%ld%ld",&x,&y);

			mat[x][y]=1;
		}

		i=ans=0;

		while(1)
		{
			mx=ls=-1;
			for(j=0;j<n;j++)
				if(mat[i][j])
				{
					if(mx<cst[j])
					{
						mx=cst[j];
						ls=j;
					}
				}
			if(ls>=0)
			{
				i=ls;
				ans+=mx;
			}
			else
				break;
		}

		printf("Case %ld: %ld %ld\n",cs++,ans,i);
	}
	return 0;
}