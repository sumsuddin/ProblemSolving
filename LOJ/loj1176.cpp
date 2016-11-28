#include<stdio.h>
#include<string.h>
#include<queue>
#define inf 1000000000
using namespace std;
queue<long>que;

long i,j,sum,t,n,w,mat[70][70],cs=1,par[70],mx;
bool vs[70],flag;
char st[20],sy[20];

void comp(long i,char st[])
{
	if(strcmp(st,"XXL")==0)
		mat[i][n+1]=1;
	else if(strcmp(st,"XL")==0)
		mat[i][n+2]=1;
	else if(strcmp(st,"L")==0)
		mat[i][n+3]=1;
	else if(strcmp(st,"M")==0)
		mat[i][n+4]=1;
	else if(strcmp(st,"S")==0)
		mat[i][n+5]=1;
	else if(strcmp(st,"XS")==0)
		mat[i][n+6]=1;
}

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
	for(i=0;i<n+8;i++)
		vs[i]=1;

	que.push(0);
	par[0]=-1;
	vs[0]=0;
	flag=0;
	while(!que.empty())
	{
		w=que.front();
		que.pop();

		if(w==n+7)
		{
			while(!que.empty())
				que.pop();
			flag=1;
			break;
		}

		for(i=0;i<=n+7;i++)
			if(vs[i] && mat[w][i]>0)
			{
				vs[i]=0;
				par[i]=w;
				que.push(i);
			}
	}

	mx=inf;

	if(flag)
	{
		update(n+7);
		rec(n+7);
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
		scanf("%ld%ld",&w,&n);

		for(i=0;i<n+8;i++)
			for(j=0;j<n+8;j++)
				mat[i][j]=0;

		for(i=1;i<=n;i++)
		{
			scanf("%s%s",st,sy);

			comp(i,st);
			comp(i,sy);
		}
		for(i=1;i<=n;i++)
			mat[0][i]=1;

		for(i=1;i<=6;i++)
			mat[n+i][n+7]=w;
		
		sum=0;
		while(bfs())
			sum++;

		if(sum==n)
			printf("Case %ld: YES\n",cs++);
		else
			printf("Case %ld: NO\n",cs++);
	}
	return 0;
}
