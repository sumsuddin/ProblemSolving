#include<stdio.h>
#include<queue>
#include<vector>
#define INF 1000000000
using namespace std;
struct node
{
	long cost ,ind;
	bool operator <(const node& now) const
	{
		return now.cost<cost;
	}
}
nod,ext;

struct sss
{
	long u,v,w;
}
sr[100050];


vector<long>vc[10050],vr[10050],wt[10050],wr[10050];
priority_queue<node>pque;

bool vst[10050];
long dist[10050],dist_b[10050],t,i,n,m,strt,des,lim,mx;

void dijk()
{
	while(!pque.empty())
	{
		nod=pque.top();
		pque.pop();

		vst[nod.ind]=0;

		for(i=0;i<vc[nod.ind].size();i++)
		{
			if(vst[vc[nod.ind][i]])
			{
				if(dist[vc[nod.ind][i]]>dist[nod.ind]+wt[nod.ind][i])
				{
					dist[vc[nod.ind][i]]=dist[nod.ind]+wt[nod.ind][i];
					ext.ind=vc[nod.ind][i];
					ext.cost=dist[vc[nod.ind][i]];
					pque.push(ext);
				}
			}
		}
	}
}

void dijk_b()
{
	while(!pque.empty())
	{
		nod=pque.top();
		pque.pop();

		vst[nod.ind]=0;

		for(i=0;i<vr[nod.ind].size();i++)
		{
			if(vst[vr[nod.ind][i]])
			{
				if(dist_b[vr[nod.ind][i]]>dist_b[nod.ind]+wr[nod.ind][i])
				{
					dist_b[vr[nod.ind][i]]=dist_b[nod.ind]+wr[nod.ind][i];
					ext.ind=vr[nod.ind][i];
					ext.cost=dist_b[vr[nod.ind][i]];
					pque.push(ext);
				}
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld%ld%ld",&n,&m,&strt,&des,&lim);

		for(i=0;i<=n;i++)
			dist[i]=dist_b[i]=INF;

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld%ld",&sr[i].u,&sr[i].v,&sr[i].w);
			vc[sr[i].u].push_back(sr[i].v);
			wt[sr[i].u].push_back(sr[i].w);
			vr[sr[i].v].push_back(sr[i].u);
			wr[sr[i].v].push_back(sr[i].w);
		}

		for(i=0;i<=n;i++)
			vst[i]=1;

		nod.ind=strt;
		dist[strt]=0;
		nod.cost=0;
		pque.push(nod);

		dijk();

		for(i=0;i<=n;i++)
			vst[i]=1;

		nod.ind=des;
		dist_b[des]=0;
		nod.cost=0;
		pque.push(nod);

		dijk_b();

		mx=-1;
		for(i=0;i<m;i++)
		{
			if(sr[i].w>mx && dist[sr[i].u]+dist_b[sr[i].v]+sr[i].w<=lim)
				mx=sr[i].w;
		}
		printf("%ld\n",mx);
		for(i=0;i<=n;i++)
			vc[i].clear(),vr[i].clear(),wt[i].clear(),wr[i].clear();
	}
	return 0;
}