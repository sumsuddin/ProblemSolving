#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;

queue<long>que;

long i,s,t,des,mat[150][150],n,m,w,a,b,q,par[150],mx,ans,cs=1;
bool vis[150],flag;

void update(long p)
{
	if(par[p]==-1)
		return ;

	if(mat[par[p]][p]<mx)
		mx=mat[par[p]][p];
	update(par[p]);
}

void rec(long p)
{
	if(par[p]==-1)
		return ;
	mat[par[p]][p]-=mx;
	mat[p][par[p]]+=mx;
	rec(par[p]);
}

long bfs()
{
	for(i=1;i<=n;i++)
		vis[i]=1;
	que.push(s);
	par[s]=-1;

	vis[s]=0;
	flag=0;
	while(!que.empty())
	{
		q=que.front();

		que.pop();

		if(q==des)
		{
			while(!que.empty())
				que.pop();
			flag=1;
			break;
		}

		for(i=1;i<=n;i++)
		{
			if(vis[i] && mat[q][i]>0)
			{
				vis[i]=0;
				par[i]=q;
				que.push(i);
			}
		}
	}
	mx=inf;
	if(flag)
	{
		update(des);
		rec(des);
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
		scanf("%ld%ld%ld",&s,&des,&m);

		ans=0;
		for(i=1;i<=n;i++)
		{
			vis[i]=1;
			for(a=1;a<=n;a++)
				mat[i][a]=0;
		}

		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			mat[a][b]+=w;
			mat[b][a]+=w;
		}

		while(bfs())
			ans+=mx;
		printf("Case %ld: %ld\n",cs++,ans);
	}
	return 0;
}