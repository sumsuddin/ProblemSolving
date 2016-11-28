#include<stdio.h>
#include<queue>
#include<vector>
#define inf 1000000000
using namespace std;

vector<long>vc[1010],wt[1010];

struct sruc
{
	long id,lit,cst;
	bool operator < (const sruc& x)const
	{
		return x.cst<cst;
	}
}
nod;

priority_queue<sruc>pque;

long cost ,lt,a,b,c,s,e,prc[1010],i,t,n,m,q,cs=1,dist[1010][1010],j;
bool flag;

long dij(long c,long s,long e)
{
	nod.id=s;
	nod.lit=0;
	nod.cst=0;

	pque.push(nod);

	while(!pque.empty())
	{
		nod=pque.top();
		pque.pop();
		a=nod.id;
		lt=nod.lit;
		cost=nod.cst;

		if(a==e)
		{
			while(!pque.empty())
				pque.pop();
			flag=1;
			return cost;
		}

		if(cost>dist[a][lt])
			continue;

		if(lt<c && dist[a][lt+1]>cost+prc[a])
		{
			dist[a][lt+1]=cost+prc[a];
			nod.id=a;
			nod.lit=lt+1;
			nod.cst=cost+prc[a];
			pque.push(nod);
		}

		for(i=0;i<vc[a].size();i++)
		{
			b=vc[a][i];
			if(wt[a][i]<=lt && dist[b][lt-wt[a][i]]>cost)
			{
				dist[b][lt-wt[a][i]]=cost;
				nod.id=b;
				nod.lit=lt-wt[a][i];
				nod.cst=cost;
				pque.push(nod);
			}
		}
	}
	return inf;
}

int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		for(i=0;i<n;i++)
			wt[i].clear(),vc[i].clear(),scanf("%ld",&prc[i]);

		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&c);

			vc[a].push_back(b);
			vc[b].push_back(a);
			wt[a].push_back(c);
			wt[b].push_back(c);
        }

		scanf("%ld",&q);

		while(q--)
		{
			scanf("%ld%ld%ld",&c,&s,&e);

			for(i=0;i<n;i++)
				for(j=0;j<=c;j++)
					dist[i][j]=inf;

			flag=0;
			s=dij(c,s,e);

			if(s<inf)
				printf("%ld\n",s);
			else
				printf("impossible\n");
		}
	}
	return 0;
}
