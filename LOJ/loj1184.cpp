#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;

queue<long>que;

struct ss
{
	long h,ag,d;
}
man[200],wman[200];

long hig,ag,mat[200][200],i,j,q,mx,ans,cs=1,t,n,m,par[200];
bool flag,vis[200];

void update(long p)
{
	if(par[p]==-1)
		return;

	if(mat[par[p]][p]<mx)
		mx=mat[par[p]][p];
	update(par[p]);
}

void rec(long p)
{
	if(par[p]==-1)
		return;

	mat[par[p]][p]-=mx;
	mat[p][par[p]]+=mx;
	rec(par[p]);
}

long bfs()
{
	for(i=0;i<=n+m+1;i++)
		vis[i]=1;

	flag=0;
	que.push(0);
	vis[0]=0;
	par[0]=-1;

	while(!que.empty())
	{
		q=que.front();
		que.pop();

		if(q==n+m+1)
		{
			while(!que.empty())
				que.pop();

			flag=1;
		}

		for(i=0;i<=n+m+1;i++)
			if(vis[i] && mat[q][i]>0)
			{
				vis[i]=0;
				par[i]=q;
				que.push(i);
			}
	}
	mx=inf;
	if(flag)
	{
		update(n+m+1);
		rec(n+m+1);
	}
	else
		mx=0;

	return mx;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<=n+m+1;i++)
			for(j=0;j<=n+m+1;j++)
				mat[i][j]=0;

		for(i=1;i<=n;i++)
			scanf("%ld%ld%ld",&man[i].h,&man[i].ag,&man[i].d);

		for(i=1;i<=m;i++)
			scanf("%ld%ld%ld",&wman[i].h,&wman[i].ag,&wman[i].d);

		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				hig=man[i].h-wman[j].h;
				if(hig<0)
					hig=-hig;

				ag=man[i].ag-wman[j].ag;
				if(ag<0)
					ag=-ag;

				if(hig<=12 && ag<=5 && man[i].d==wman[j].d)
					mat[i][n+j]=1;
			}

		for(i=1;i<=n;i++)
			mat[0][i]=1;
		for(i=1;i<=m;i++)
			mat[n+i][n+m+1]=1;

		ans=0;
		while(bfs())
			ans++;

		printf("Case %ld: %ld\n",cs++,ans);
	}
	return 0;
}