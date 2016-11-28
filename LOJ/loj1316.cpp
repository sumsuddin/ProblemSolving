#include<stdio.h>
#include<queue>
#include<vector>
#define inf 100000000
using namespace std;
vector<long>vc[550],wt[550];
struct sr
{
	long id,cst;

	bool operator <(const sr& xxxx)
		const { return xxxx.cst<cst;}
}
nod;

struct ssr
{
	long id,cst,vs;
	bool operator <(const ssr& xxx)
		const { return xxx.cst<cst;}
}
node;

priority_queue<sr>pque;
priority_queue<ssr>pqq;

long dist[550][550],i,a,b,stor[550],t,n,m,s,w,cs=1,ind[550],dst[20][100000],x,xx,mx,ans;
bool chk[550];
void dij(long src)
{
	long i;
	dist[src][src]=0;
	nod.id=src;
	nod.cst=0;
	pque.push(nod);

	while(!pque.empty())
	{
		nod=pque.top();
		pque.pop();

		a=nod.id;
		b=nod.cst;

		if(b>dist[src][a])
			continue;

		for(i=0;i<vc[a].size();i++)
		{
			if(dist[src][vc[a][i]]>dist[src][a]+wt[a][i])
			{
				dist[src][vc[a][i]]=dist[src][a]+wt[a][i];
				nod.id=vc[a][i];
				nod.cst=dist[src][a]+wt[a][i];
				pque.push(nod);
			}
		}
	}
}

void dijk()
{
	for(i=0;i<s;i++)
	{
		if(stor[i]==0 || stor[i]==n-1)
			continue;
		node.id=stor[i];
		node.cst=dist[0][stor[i]];
		node.vs=1<<ind[stor[i]];
		dst[ind[node.id]][node.vs]=node.cst;
		pqq.push(node);
	}

	while(!pqq.empty())
	{
		node=pqq.top();
		pqq.pop();
		a=node.id;
		b=node.vs;
		w=node.cst;

		if(w>dst[ind[a]][b])
			continue;

		x=b;
		xx=0;
		while(x)
			xx+=(x%2),x>>=1;
		if(mx<xx || (mx==xx && ans>w+dist[a][n-1]))
		{
			mx=xx;
			ans=w+dist[a][n-1];
		}

		for(i=0;i<s;i++)
		{
			if(stor[i]==n-1 || stor[i]==0)
				continue;

			if(dist[a][stor[i]]<inf && dst[ind[stor[i]]][b | (1<<i)]>w+dist[a][stor[i]])
			{
				dst[ind[stor[i]]][b | (1<<i)]=w+dist[a][stor[i]];
				node.id=stor[i];
				node.cst=w+dist[a][stor[i]];
				node.vs=b | (1<<i);
				pqq.push(node);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&n,&m,&s);

		for(i=0;i<n;i++)
		{
			vc[i].clear(),wt[i].clear();
			for(a=0;a<n;a++)
				dist[i][a]=inf;
			chk[i]=0;
		}

		for(i=0;i<s;i++)
		{
			scanf("%ld",&stor[i]),ind[stor[i]]=i,chk[stor[i]]=1;
			for(a=0;a<=(1<<s);a++)
				dst[i][a]=inf;
		}


		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			vc[a].push_back(b);
			wt[a].push_back(w);
		}

		if(chk[0]==0)
			dij(0);
		for(i=0;i<s;i++)
			dij(stor[i]);

		mx=-1;
		ans=inf;

		if(dist[0][n-1]<inf)
			mx=0,ans=dist[0][n-1];

		dijk();
		if(chk[0])
			mx++;
		if(chk[n-1])
			mx++;

		if(ans<inf)
			printf("Case %ld: %ld %ld\n",cs++,mx,ans);
		else
			printf("Case %ld: Impossible\n",cs++);
	}
	return 0;
}