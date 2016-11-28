#include<stdio.h>
#include<queue>
using namespace std;

queue<long>que;

struct 
{
	long a,b,c,d,e,f;
}
nd[100000];
long i,sum,mp,n,m,pp,j,des,st,p,par[100000];
bool bu[100000],flag;

void fy()
{
	if(i<=n && i>0 && flag && bu[i])
	{
		if(i==des)
		{
			while(!que.empty())
				que.pop();
			printf("%ld\n",par[p]+1);
			flag=0;
		}
		else
		{
			bu[i]=0;
			par[i]=par[p]+1;
			que.push(i);
		}
	}
}

void bfs()
{
	que.push(st);
	par[st]=0;
	flag=1;

	while(!que.empty())
	{
		p=que.front();
		que.pop();

		i=nd[nd[nd[p].a].a].b;
		fy();

		i=nd[nd[nd[p].a].a].f;
		fy();

		i=nd[nd[nd[p].b].b].c;
		fy();

		i=nd[nd[nd[p].b].b].a;
		fy();

		i=nd[nd[nd[p].c].c].d;
		fy();

		i=nd[nd[nd[p].c].c].b;
		fy();

		i=nd[nd[nd[p].d].d].e;
		fy();

		i=nd[nd[nd[p].d].d].c;
		fy();

		i=nd[nd[nd[p].e].e].f;
		fy();

		i=nd[nd[nd[p].e].e].d;
		fy();

		i=nd[nd[nd[p].f].f].a;
		fy();

		i=nd[nd[nd[p].f].f].e;
		fy();
	}
}

void make()
{
	sum=2;i=0;

	for(mp=0;i<=10000;mp++)
	{
		i=sum+=6*mp;

		nd[sum-1].a=sum;
		nd[sum].d=sum-1;

		nd[nd[sum-1].b].f=sum;
		nd[sum].c=nd[sum-1].b;
		i++;

		pp=sum+mp;
		for(j=sum+1;mp && j<pp;j++)
		{
			nd[j].e=j-1;
			nd[j-1].b=j;

			nd[j].d=nd[j-1].c;
			nd[nd[j-1].c].a=j;

			nd[j].c=nd[nd[j-1].c].b;
			nd[nd[nd[j-1].c].b].f=j;
			i++;
		}

		if(mp)
		{
			nd[i].e=i-1;
			nd[i-1].b=i;

			nd[i].d=nd[i-1].c;
			nd[nd[i-1].c].a=i++;
		}

		pp=i+mp;
		for(j=i;mp && j<pp;j++)
		{
			nd[j-1].c=j;
			nd[j].f=j-1;

			nd[j].e=nd[j-1].d;
			nd[nd[j-1].d].b=j;

			nd[j].d=nd[nd[j-1].d].c;
			nd[nd[nd[j-1].d].c].a=j;
			i++;
		}

		nd[i-1].c=i;
		nd[i].f=i-1;

		nd[i].e=nd[i-1].d;
		nd[nd[i-1].d].b=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].a=j-1;
			nd[j-1].d=j;

			nd[j].f=nd[j-1].e;
			nd[nd[j-1].e].c=j;

			nd[j].e=nd[nd[j-1].e].d;
			nd[nd[nd[j-1].e].d].b=j;
			i++;
		}
		nd[i].a=i-1;
		nd[i-1].d=i;

		nd[i].f=nd[i-1].e;
		nd[nd[i-1].e].c=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].b=j-1;
			nd[j-1].e=j;

			nd[j].a=nd[j-1].f;
			nd[nd[j-1].f].d=j;

			nd[j].f=nd[nd[j-1].f].e;
			nd[nd[nd[j-1].f].e].c=j;
			i++;
		}
		nd[i].b=i-1;
		nd[i-1].e=i;

		nd[i].a=nd[i-1].f;
		nd[nd[i-1].f].d=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].c=j-1;
			nd[j-1].f=j;

			nd[j].b=nd[j-1].a;
			nd[nd[j-1].a].e=j;

			nd[j].a=nd[nd[j-1].a].f;
			nd[nd[nd[j-1].a].f].d=j;
			i++;
		}
		nd[i].c=i-1;
		nd[i-1].f=i;

		nd[i].b=nd[i-1].a;
		nd[nd[i-1].a].e=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].d=j-1;
			nd[j-1].a=j;

			nd[j].c=nd[j-1].b;
			nd[nd[j-1].b].f=j;

			nd[j].b=nd[nd[j-1].b].a;
			nd[nd[nd[j-1].b].a].e=j;
			i++;
		}
		nd[i].d=i-1;
		nd[i-1].a=i;

		nd[i].c=nd[i-1].b;
		nd[nd[i-1].b].f=i;

		nd[i].b=nd[nd[i-1].b].a;
		nd[nd[nd[i-1].b].a].e=i;
	}
}

int main()
{
	make();
	nd[0].a=nd[0].b=nd[0].c=nd[0].d=nd[0].e=nd[0].f=0;
	while(~scanf("%ld%ld",&n,&m))
	{	
		for(i=1;i<=10000;i++)
			bu[i]=1;

		while(m--)
		{
			scanf("%ld",&i);
			bu[i]=0;
		}
		scanf("%ld%ld",&st,&des);
		if(st==des && bu[st])
			printf("0\n");
		else
			bfs();

		if(flag)
			printf("Impossible.\n");
	}
	return 0;
}
