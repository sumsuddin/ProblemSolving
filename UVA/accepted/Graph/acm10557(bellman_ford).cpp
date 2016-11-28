#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[150];
struct ss
{
	long u,v;
}
sr[10000];
long i,dist[150],eg,j,cst[150],n,m,p,ps[150];
bool flag,vst[150];

void dfs(long p,long st)
{
	long i;

	if(flag)
		return;
	if(p==n)
	{
		if(st)
			flag=1;
		return;
	}

	for(i=0;i<vc[p].size();i++)
		if(vst[vc[p][i]])
		{
			vst[vc[p][i]]=0;
			dfs(vc[p][i],(ps[vc[p][i]])?1:st);
		}
}

int main()
{
	while(~scanf("%ld",&n) && n>=0)
	{
		eg=0;

		for(i=1;i<=n;i++)
			vc[i].clear();

		for(i=1;i<=n;i++)
		{
			ps[i]=0;
			vst[i]=1;
			dist[i]=-100000000;
			scanf("%ld%ld",&cst[i],&m);

			for(j=0;j<m;j++)
			{
				scanf("%ld",&p);
				sr[eg].u=i;
				sr[eg++].v=p;
				vc[i].push_back(p);
			}
		}
		dist[1]=100;

		for(i=0;i<n;i++)
		{
			for(j=0;j<eg;j++)
			{
				if(dist[sr[j].v]<dist[sr[j].u]+cst[sr[j].v] && dist[sr[j].u]>0)
					dist[sr[j].v]=dist[sr[j].u]+cst[sr[j].v];
			}
		}
		flag=1;
		for(i=1;i<=n;i++)
			if(dist[i]<=0)
				flag=0;

		if(flag==0)
			for(i=0;i<eg;i++)
				if(dist[sr[i].v]<dist[sr[i].u]+cst[sr[i].v] && dist[sr[i].u]>0)
					ps[sr[i].v]=1;
		if(flag==0)
			dfs(1,ps[1]);

		if(flag)
			printf("winnable\n");
		else
			printf("hopeless\n");
	}
	return 0;
}
