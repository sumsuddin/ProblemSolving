#include<stdio.h>
#include<queue>
#include<vector>
#define inf 1000000000
using namespace std;
struct sr
{
	long id,usd,cst;
	bool operator <(const sr& x)
		const {return x.cst<cst;}
}
nod;

vector<long>vc[10050],wt[10050];
vector<bool>typ[10050];
priority_queue<sr>pque;

long a,b,w,n,m,k,d,cs=1,dist[100050][20],i,t;

long dij(long s)
{
	nod.id=s;
	nod.cst=0;
	nod.usd=0;

	pque.push(nod);

	while(!pque.empty())
	{
		nod=pque.top();
		pque.pop();
		a=nod.id;
		b=nod.usd;
		w=nod.cst;

		if(w>dist[a][b])
			continue;

		if(a==n-1)
		{
			while(!pque.empty())
				pque.pop();
			return w;
		}

		for(i=0;i<vc[a].size();i++)
		{
			if(b+typ[a][i]<=d && dist[vc[a][i]][b+typ[a][i]]>w+wt[a][i])
			{
				dist[vc[a][i]][b+typ[a][i]]=w+wt[a][i];
				nod.id=vc[a][i];
				nod.usd=b+typ[a][i];
				nod.cst=w+wt[a][i];
				pque.push(nod);
			}
		}
	}
	return inf;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld%ld",&n,&m,&k,&d);

		for(i=0;i<=n;i++)
		{
			vc[i].clear();
			typ[i].clear();
			wt[i].clear();

			for(a=0;a<=d;a++)
				dist[i][a]=inf;
		}
		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);
			vc[a].push_back(b);
			typ[a].push_back(0);
			wt[a].push_back(w);
		}
		while(k--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			vc[a].push_back(b);
			typ[a].push_back(1);
			wt[a].push_back(w);
		}



		a=dij(0);
		if(a<inf)
			printf("Case %ld: %ld\n",cs++,a);
		else
			printf("Case %ld: Impossible\n",cs++);
	}
	return 0;
}