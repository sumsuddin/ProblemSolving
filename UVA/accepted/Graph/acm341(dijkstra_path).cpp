#include<cstdio>
#include<queue>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
struct bal
{
	long node,cost;
	bool operator < ( const bal& b ) const
	{
		return b.cost<cost;
	}
}q;

priority_queue<bal>qt;
long s[100050],dist[100050],par[100050],sourc,cs=1;
typedef vector<long>ct;
ct ad[100050];
ct cst[100050];

void prin(long p)
{
	if(p==sourc)
	{
		printf(" %ld",p);
		return;
	}
	prin(par[p]);
	printf(" %ld",p);
}


int main()
{
	long n,e,i,j,u,v,w,di;
	while(scanf("%ld",&n) && n)
	{
		for(i=1;i<=n;i++)
		dist[i]=1000000000,ad[i].clear(),cst[i].clear(),s[i]=0;

		for(i=1;i<=n;i++)
		{
			scanf("%ld",&e);
			for(j=1;j<=e;j++)
			{
				scanf("%ld%ld",&v,&w);
				ad[i].push_back(v);
				cst[i].push_back(w);
			}
		}
		scanf("%ld%ld",&sourc,&di);

		dist[sourc]=0;
		q.node=sourc;
		q.cost=0;
		qt.push(q);

		while(!qt.empty())
		{
			u=qt.top().node;
			qt.pop();
			s[u]=1;
			for(j=0;j<ad[u].size();j++)
			{
				v=ad[u][j];
				if(dist[v]>dist[u]+cst[u][j])
				{	
					par[v]=u;
					dist[v]=dist[u]+cst[u][j];
					if(s[v]==0)
					{
						q.node=v;
						q.cost=dist[v];
						qt.push(q);
					}
				}
			}
		}
		printf("Case %ld: Path =",cs++);
		prin(di);
		printf("; %ld second delay\n",dist[di]);
	}
	return 0;
}