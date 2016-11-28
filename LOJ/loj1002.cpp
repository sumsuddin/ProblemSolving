#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct ss
{
	long p,q,w;
}
sr[20000];

vector<long>vc[20000],ww[20000];

long i,t,n,m,dist[550],rank[550],a[550],cs=1;
bool vst[550];

int cmp(ss a,ss b)
{
	return a.w<b.w;
}

void init()
{
	for(i=0;i<n;i++)
	{
		dist[i]=100000000;
		a[i]=i;
		rank[i]=0;
	}
}

long parent(long p)
{
	long bc=p;
	while(a[p]!=p)
		p=a[p];
	return a[bc]=p;
}

void mst()
{
	sort(sr,sr+m,cmp);

	long i,p1,p2;
		for(i=0;i<m;i++)
		{
			p1=parent(sr[i].p);
			p2=parent(sr[i].q);
			if(p1!=p2)
			{
				if(rank[p1]>rank[p2])
				{
					a[p2]=p1;
					rank[p1]++;
				}
				else
				{
					a[p1]=p2;
					rank[p2]++;
				}
				vc[p1].push_back(p2);
				ww[p1].push_back(sr[i].w);
				vc[p2].push_back(p1);
				ww[p2].push_back(sr[i].w);
			}
		}
	for(i=0;i<n;i++)
		vst[i]=1;
}

void dfs(long src,long cst)
{
	for(long i=0;i<vc[src].size();i++)
	{
		if(vst[vc[src][i]])
		{
			vst[vc[src][i]]=0;
			dfs(vc[src][i],(cst>ww[src][i])?cst:ww[src][i]);
			dist[vc[src][i]]=(cst>ww[src][i])?cst:ww[src][i];
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<m;i++)
			scanf("%ld%ld%ld",&sr[i].p,&sr[i].q,&sr[i].w);

		init();
		mst();
		scanf("%ld",&m);
		printf("Case %ld:\n",cs++);
		vst[m]=0;
		dfs(m,0);
		dist[m]=0;
		for(i=0;i<n;i++)
		{
			if(dist[i]==100000000)
				printf("Impossible\n");
			else
				printf("%ld\n",dist[i]);
			vc[i].clear();
			ww[i].clear();
		}
	}
	return 0;
}