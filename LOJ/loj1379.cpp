#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<long long>vc[10050],wt[10050],vt[10050],ww[10050];
long long t,n,m,s,e,cs=1,p,i,a,b,w,dist[10050],rdist[10050];

struct sss
{
	long long a,b,w;
}
sr[50050];

struct chk
{
	long long node ,cost;

	bool operator < (const chk& x)const
	{
		return x.cost<cost;
	}
}
nod;

priority_queue<chk>pque;

void dij(long long dir)
{
	while(!pque.empty())
	{
		a=pque.top().node;
		b=pque.top().cost;
		pque.pop();

		if(dir==0)
		{
			for(i=0;i<vc[a].size();i++)
			{
				if(dist[vc[a][i]]>dist[a]+wt[a][i])
				{
					dist[vc[a][i]]=dist[a]+wt[a][i];
					nod.cost=dist[vc[a][i]];
					nod.node=vc[a][i];
					pque.push(nod);
				}
			}
		}
		else
		{
			for(i=0;i<vt[a].size();i++)
			{
				if(rdist[vt[a][i]]>rdist[a]+ww[a][i])
				{
					rdist[vt[a][i]]=rdist[a]+ww[a][i];
					nod.cost=rdist[vt[a][i]];
					nod.node=vt[a][i];
					pque.push(nod);
				}
			}
		}
	}
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&e,&p);

		for(i=1;i<=n;i++)
			vc[i].clear(),wt[i].clear(),vt[i].clear(),ww[i].clear(),dist[i]=rdist[i]=10000000000000LL;

		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&w);

			sr[i].a=a;
			sr[i].b=b;
			sr[i].w=w;

			vc[a].push_back(b);
			wt[a].push_back(w);
			vt[b].push_back(a);
			ww[b].push_back(w);
		}

		nod.node=s;
		nod.cost=0;
		pque.push(nod);
		dist[s]=0;
		dij(0);

		nod.node=e;
		nod.cost=0;
		pque.push(nod);
		rdist[e]=0;
		dij(1);

		w=10000000000000LL;
		a=-1;
		for(i=0;i<m;i++)
		{
			if(dist[sr[i].a]+rdist[sr[i].b]+sr[i].w <w || (dist[sr[i].a]+rdist[sr[i].b]+sr[i].w ==w && a<sr[i].w))
				a=sr[i].w,w=dist[sr[i].a]+rdist[sr[i].b]+sr[i].w;
		}
		if(w>p)
			a=-1;
		printf("Case %lld: %lld\n",cs++,a);
	}
	return 0;
}
