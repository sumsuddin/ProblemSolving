#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct sr
{
	long tm,id;
}
nd[1050];

vector<long>vc[1050],vt[1050];
long i,j,n,m,t,dist[1050],u[2050],v[2050],cst[2050],cs=1,lst,ans[1050],scc[1050],tim;
bool vs[1050],vss[1050];

bool cmp(sr a,sr b)
{
	return a.tm>b.tm;
}

void call(long p)
{
	vs[p]=0;
	for(long i=0;i<vt[p].size();i++)
		if(vs[vt[p][i]])
			tim++,call(vt[p][i]);

	nd[p].tm=++tim;
}

void call_agn(long p)
{
	vs[p]=0;
	for(long i=0;i<vc[p].size();i++)
		if(vs[vc[p][i]])
			call_agn(vc[p][i]);
	scc[p]=tim;
}

void add(long p)
{
	vs[p]=0;
	vss[scc[p]]=1;
	long i;
	for(i=0;i<vt[p].size();i++)
		if(vs[vt[p][i]])
			add(vt[p][i]);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			vs[i]=1,dist[i]=10000000,vc[i].clear(),vt[i].clear(),nd[i].id=i;

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld%ld",&u[i],&v[i],&cst[i]);
			vt[v[i]].push_back(u[i]);
			vc[u[i]].push_back(v[i]);
		}

		tim=0;
		for(i=0;i<n;i++)
			if(vs[i])
				call(i);
		sort(nd,nd+n,cmp);

		for(i=0;i<n;i++)
			vs[i]=1;

		tim=0;
		for(i=0;i<n;i++)
			if(vs[nd[i].id])
				tim++,call_agn(nd[i].id);

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(dist[v[j]]>dist[u[j]]+cst[j] && scc[v[j]]==scc[u[j]])
					dist[v[j]]=dist[u[j]]+cst[j];
		
		for(i=1;i<=tim;i++)
			vss[i]=0;

		lst=0;
		for(i=0;i<m;i++)
			if(dist[v[i]]>dist[u[i]]+cst[i] && scc[u[i]]==scc[v[i]])
				vss[scc[u[i]]]=1;

		for(i=0;i<n;i++)
			vs[i]=1;

		for(i=0;i<n;i++)
		{
			if(vs[i] && vss[scc[i]])
				add(i);
		}
			

		for(i=0;i<n;i++)
			if(vss[scc[i]])
				ans[lst++]=i;
		sort(ans,ans+lst);

		if(lst)
			printf("Case %ld:",cs++);
		else
			printf("Case %ld: impossible",cs++);
		for(i=0;i<lst;i++)
			printf(" %ld",ans[i]);

		printf("\n");
	}
	return 0;
}