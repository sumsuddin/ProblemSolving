#include<stdio.h>
#include<string.h>

long i,j,n,p,ans,mat[500][500],mx,r,x,y,w,k,cs=1,q;
bool flag=0;

long min(long a,long b,long c)
{
	if(b==1000000||c==1000000)
		mx=1000000;
	else
		if(b>=c)
			mx=b;
		else
			mx=c;
	if(a<=mx && a!=1000000 || mx==1000000)
		return a;
	else
		return mx;
}

int main()
{

	while(scanf("%ld%ld%ld",&n,&r,&q) && (n||r||q))
	{
		if(flag)
			printf("\n");
		else
			flag=1;

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=1000000;
		ans=1000000;
		p=1;

		for(i=0;i<r;i++)
		{
			scanf("%ld%ld%ld",&x,&y,&w);

			mat[x][y]=w;
			mat[y][x]=w;
		}


		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					mat[i][j]=min(mat[i][j],mat[i][k],mat[k][j]);

				}
			}
		}
		printf("Case #%ld\n",cs++);
		for(i=0;i<q;i++)
		{
			scanf("%ld%ld",&x,&y);
			if(mat[x][y]>=1000000)
				printf("no path\n");
			else
				printf("%ld\n",mat[x][y]);
		}
	}
	return 0;
}