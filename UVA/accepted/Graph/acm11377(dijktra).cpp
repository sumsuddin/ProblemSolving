#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
vector<long>vc[20050];
long i,j,dist[20050],large,n,hp,p,eg,source,src,t,dst,cs=1,k,a,b,cst[20040];
bool vst[20050],flag;
struct ss
{
	long cost,nd;

	bool operator < ( const ss& u ) const
	{
		return u.cost<cost;
	}
} node,pq;

priority_queue<ss>pque;

void dijk()
{
	long i;

	for(i=0;i<=n;i++)
		vst[i]=1,dist[i]=(long)pow(10,9);

	node.cost=cst[src];
	node.nd=src;
	pque.push(node);
	
	while(!pque.empty())
	{
		pq=pque.top();
		pque.pop();

		vst[pq.nd]=0;

		if(pq.nd==dst)
		{
			flag=0;
			while(!pque.empty())
				pque.pop();

			break;
		}

		for(i=0;i<vc[pq.nd].size();i++)
		{
			if(dist[vc[pq.nd][i]]>pq.cost+cst[vc[pq.nd][i]])
				dist[vc[pq.nd][i]]=pq.cost+cst[vc[pq.nd][i]];
		
			if(vst[vc[pq.nd][i]])
			{
				vst[vc[pq.nd][i]]=0;
				node.nd=vc[pq.nd][i];
				node.cost=dist[vc[pq.nd][i]];
				pque.push(node);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&n,&eg,&k);

		for(i=1;i<=n;i++)
			cst[i]=1,vc[i].clear();

		for(i=0;i<k;i++)
		{
			scanf("%ld",&src);
			cst[src]=0;
		}

		for(i=0;i<eg;i++)
		{
			scanf("%ld%ld",&a,&b);

			vc[a].push_back(b);
			vc[b].push_back(a);
		}

		printf("Case %ld:\n",cs++);
		scanf("%ld",&k);
		while(k--)
		{
			scanf("%ld%ld",&src,&dst);
			if(src==dst)
			{
				printf("0\n");
				continue;
			}
			flag=1;
			dijk();
			if(flag)
				 printf("-1\n");
			else
				 printf("%ld\n",dist[dst]);
		}
		printf("\n");
	}
	return 0;
}
