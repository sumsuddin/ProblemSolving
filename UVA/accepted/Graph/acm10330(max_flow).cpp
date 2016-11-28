#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;
queue<long>que;
long mat[520][520],sum,w,a,b,i,j,q,par[520],mx,n,m;
bool vs[520],flag;
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
		return ;

	mat[par[p]][p]-=mx;
	mat[p][par[p]]+=mx;
	rec(par[p]);
}

long bfs()
{
	for(i=0;i<=2*n+1;i++)
		vs[i]=1;
	que.push(0);

	vs[0]=0;
	par[0]=-1;
	flag=0;
	while(!que.empty())
	{
		q=que.front();
		que.pop();

		if(q==2*n+1)
		{
			while(!que.empty())
				que.pop();

			flag=1;
			break;
		}

		for(i=0;i<=2*n+1;i++)
		{
			if(vs[i] && mat[q][i]>0)
			{
				vs[i]=0;
				par[i]=q;
				que.push(i);
			}
		}
	}
	mx=inf;
	if(flag)
	{
		update(2*n+1);
		rec(2*n+1);
	}
	else
		mx=0;

	return mx;
}

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<=2*n+1;i++)
			for(j=0;j<=2*n+1;j++)
				mat[i][j]=0;

		for(i=1;i<=n;i++)
			scanf("%ld",&a),mat[i][n+i]=a;

		scanf("%ld",&m);

		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);
			mat[n+a][b]=w;
		}
		scanf("%ld%ld",&a,&b);

		while(a--)
		{
			scanf("%ld",&w);
			mat[0][w] = inf;
		}
		while(b--)
		{
			scanf("%ld",&w);
			mat[n+w][2*n+1]=inf;
		}
		sum=0;
		while(bfs())
			sum+=mx;
		printf("%ld\n",sum);
	}
	return 0;
}
