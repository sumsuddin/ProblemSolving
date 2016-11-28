#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
vector<long>vc[2050],wt[2050];
long i,j,dist[2050],large,n,hp,p,m,a,b,w,src[1000],t,des,ii,mx,mn;
bool vst[2050],prs[2050],flag;
char st[100];
struct 
{
	long cost,nd;
}
node[200050],sw;

void minheap(long i,long n)
{
	large=i;
	if(i*2<=n && node[i*2].cost<node[large].cost)
		large=i*2;
	if(i*2+1<=n && node[i*2+1].cost<node[large].cost)
		large=i*2+1;

	if(large!=i)
	{
        sw=node[i];
        node[i]=node[large];
        node[large]=sw;
		minheap(large,n);
	}
}

void dijk(long eg)
{
	hp=1;
	for(i=0;i<=n;i++)
		vst[i]=1,dist[i]=(long)pow(10,9);

	dist[eg]=node[eg].cost=0;
	node[hp].cost=0;
	node[hp++].nd=eg;

	for(i=0;i<m;i++)
	{
		dist[src[i]]=node[src[i]].cost=0;
		node[hp].cost=0;
		node[hp].nd=src[i];
		eg=hp++;
		while(eg>1 && node[eg/2].cost>node[eg].cost)
		{
			sw=node[eg];
			node[eg]=node[eg/2];
			node[eg/2]=sw;
			eg/=2;
		}
	}
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
						sw=node[eg];
						node[eg]=node[eg/2];
						node[eg/2]=sw;
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
		scanf("%ld%ld",&m,&n);
		for(i=0;i<=n;i++)
			prs[i]=0;

		for(i=0;i<m;i++)
			scanf("%ld",&src[i]),prs[src[i]]=1;
		getchar();
		while(gets(st) && st[0])
		{
			sscanf(st,"%ld%ld%ld",&a,&b,&w);

			vc[a].push_back(b);
			vc[b].push_back(a);
			wt[a].push_back(w);
			wt[b].push_back(w);
		}
		mn=(long)pow(10,9);
		flag=1;
		for(ii=1;ii<=n;ii++)
		{
			mx=0;
			dijk(ii);
			for(i=1;i<=n;i++)
				if(dist[i]>mx)
					mx=dist[i];
			if(mx<mn || (mx==mn && prs[ii]==0 && flag))
			{
				if(prs[ii]==1)
					flag=1;
				else
					flag=0;

				mn=mx,des=ii;
			}
		}
		printf("%ld\n",des);
		if(t)
			printf("\n");


		for(i=0;i<=n;i++)
			vc[i].clear(),wt[i].clear();
	}
	return 0;
}
