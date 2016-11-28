#include<stdio.h>
#include<string.h>

long i,j,n,p,ans,mat[500][500],mx,r,x,y,w,k,cs=1;

char st[50],sy[50],sr[500][50];

long min(long a,long b,long c)
{
	if(b==1000000||c==1000000)
		mx=1000000;
	else
		if(b<=c)
			mx=b;
		else
			mx=c;
	if(a>=mx && a!=1000000 || mx==1000000)
		return a;
	else
		return mx;
}

int main()
{

	while(scanf("%ld%ld",&n,&r) && (n||r))
	{

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=1000000;
		ans=1000000;
		p=1;

		for(i=0;i<r;i++)
		{
			scanf("%s%s%ld",st,sy,&w);
			x=y=0;
			for(j=1;j<p;j++)
				if(strcmp(sr[j],st)==0)
				{
					x=j;
					break;
				}
			if(x==0)
			{
				strcpy(sr[p],st);
				x=p++;
			}

			for(j=1;j<p;j++)
				if(strcmp(sr[j],sy)==0)
				{
					y=j;
					break;
				}
			if(y==0)
			{
				strcpy(sr[p],sy);
				y=p++;
			}
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
		scanf("%s%s",st,sy);

		for(j=1;j<=n;j++)
			if(strcmp(sr[j],st)==0)
			{
				x=j;
				break;
			}
		for(j=1;j<=n;j++)
			if(strcmp(sr[j],sy)==0)
			{
				y=j;
				break;
			}

		printf("Scenario #%ld\n%ld tons\n\n",cs++,mat[x][y]);
	}
	return 0;
}