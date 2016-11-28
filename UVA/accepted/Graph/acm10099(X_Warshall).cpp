#include<stdio.h>
#include<string.h>

long i,j,n,p,ans,mat[500][500],mx,r,x,y,w,k,cs=1,q,pas;


long min(long a,long b,long c)
{
	if(b==100000000||c==100000000)
		mx=100000000;
	else
		if(b<=c)
			mx=b;
		else
			mx=c;
	if(a>=mx && a!=100000000 || mx==100000000)
		return a;
	else
		return mx;
}

int main()
{

	while(scanf("%ld%ld",&n,&r) && (n || r))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=100000000;
		ans=100000000;
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
		q=1;
		scanf("%ld%ld%ld",&x,&y,&pas);

		mat[x][y]--;
		
		if(pas%mat[x][y]==0)
			n=0;
		else
			n=1;
		n+=pas/mat[x][y];

		printf("Scenario #%ld\nMinimum Number of Trips = %ld\n\n",cs++,n);
	}
	return 0;
}