#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
vector<long>vc[200050],wt[200050];
long i,j,dist[200050],large,n,hp,p,eg,a,b,w,source,src,t,dst,cs=1;
bool vst[200050];
struct 
{
	long cost,nd;
}
node[200050];

void minheap(long i,long n)
{
	large=i;
	if(i*2<=n && node[i*2].cost<node[large].cost)
		large=i*2;
	if(i*2+1<=n && node[i*2+1].cost<node[large].cost)
		large=i*2+1;

	if(large!=i)
	{
        node[20010]=node[i];
        node[i]=node[large];
        node[large]=node[20010];
		minheap(large,n);
	}
}

void dijk(long src)
{
	hp=1;
	for(i=0;i<n;i++)
		vst[i]=1,dist[i]=(long)pow(10,9);

	dist[src]=node[src].cost=0;
	node[hp].cost=0;
	node[hp].nd=src;
	minheap(1,hp++);
	while(hp>1)
	{
		p=node[1].nd;
		vst[p]=0;
		node[0]=node[1];

		node[1]=node[--hp];

		minheap(1,hp-1);

		for(j=0;j<vc[p].size();j++)
		{
			if(node[0].cost+wt[p][j]<dist[vc[p][j]])
			{
				dist[vc[p][j]]=node[0].cost+wt[p][j];
				if(vst[vc[p][j]])
				{
					node[hp].cost=dist[vc[p][j]];
					node[hp].nd=vc[p][j];
					eg=hp++;					
					while(eg>1 && node[eg/2].cost>node[eg].cost)
					{
						node[20010]=node[eg];
						node[eg]=node[eg/2];
						node[eg/2]=node[20010];
						eg/=2;
					}
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
		scanf("%ld%ld%ld%ld",&n,&eg,&src,&dst);
		for(i=0;i<eg;i++)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			vc[a].push_back(b);
			vc[b].push_back(a);
			wt[a].push_back(w);
			wt[b].push_back(w);
		}

		dijk(src);
		if((long)pow(10,9)==dist[dst])
		     printf("Case #%ld: unreachable\n",cs++);
		else
		     printf("Case #%ld: %ld\n",cs++,dist[dst]);

		for(i=0;i<=n;i++)
			vc[i].clear(),wt[i].clear();
	}
	return 0;
}
