#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;
queue<long>que;

long n,m,i,j,par[300],q,mx,mat[300][300],a[300],b[300],t,ans,cs=1,l,h;
bool vis[300],flag;

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
	que.push(n+m+1);
	vis[n+m+1]=0;
	flag=0;
	par[n+m+1]=-1;

	while(!que.empty())
	{
		q=que.front();
		que.pop();

		if(q==0)
		{
			flag=1;
			while(!que.empty())
				que.pop();
			break;
		}

		if(q<=n)
			l=n+1,h=n+m+1;
		else
			l=0,h=n;

		for(i=l;i<=h;i++)
		{
			if(vis[i] && mat[q][i]>0)
			{
				vis[i]=0;
				que.push(i);
				par[i]=q;
			}
		}
	}
	mx=inf;
	if(flag)
	{
		update(0);
		rec(0);
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
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);

		scanf("%ld",&m);

		for(i=0;i<=n+m+1;i++)
			for(j=0;j<=n+m+1;j++)
				mat[i][j]=0;

		for(i=1;i<=m;i++)
			scanf("%ld",&b[i]);

		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(b[j]%a[i]==0)
					mat[i][n+j]=1;
  
		for(i=1;i<=n;i++)
			mat[n+m+1][i]=1;
		for(i=1;i<=m;i++)
			mat[n+i][0]=1;
		ans=0;
		while(bfs())
			ans++;

		printf("Case %ld: %ld\n",cs++,ans);
	}
	return 0;
}
