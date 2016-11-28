#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;
queue<long>que;
long i,j,n,m,a,b,w,mat[300][300],sum,par[300],mx;
bool vs[300],flag;

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
	for(i=1;i<=2*n;i++)
		vs[i]=1;

	flag=0;
	que.push(1);
	vs[1]=0;
	par[1]=-1;

	while(!que.empty())
	{
		a=que.front();
		que.pop();

		if(a==n)
		{
			while(!que.empty())
				que.pop();
			flag=1;
			break;
		}

		for(i=1;i<=2*n;i++)
		{
			if(vs[i] && mat[a][i]>0)
			{
				vs[i]=0;
				par[i]=a;
				que.push(i);
			}
		}
	}
	mx=inf;
	if(flag)
	{
		update(n);
		rec(n);
	}
	else
		mx=0;
	return mx;
}


int main()
{
	while(scanf("%ld%ld",&n,&m) && (n>0))
	{
		for(i=0;i<=2*n;i++)
			for(j=0;j<=2*n;j++)
				mat[i][j]=0;

		mat[1][n+1]=inf;
		mat[n][n+n]=inf;

		for(i=2;i<n;i++)
		{
			scanf("%ld%ld",&b,&a);

			mat[b][n+b]=a;
			mat[n+b][b]=a;
		}

		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			mat[n+a][b]=w;
			mat[n+b][a]=w;
		}

		sum=0;
		while(bfs())
			sum+=mx;

		printf("%ld\n",sum);
	}
	return 0;
}
