#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;
queue<long>que;
long i,j,t,n,m,a,b,w,mat[300][300],sum,par[300],cs=1,mx;
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
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<=2*n;i++)
			for(j=0;j<=2*n;j++)
				mat[i][j]=0;

		mat[1][n+1]=inf;
		mat[n][n+n]=inf;

		for(i=2;i<n;i++)
		{
			scanf("%ld",&a);

			mat[i][n+i]=a;
			mat[n+i][i]=a;
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

		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}