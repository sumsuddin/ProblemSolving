#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[300];
long n,t,m,dist[250],u[1000050],v[1000050],i,j,q,des,cst[1000050],bs[250],cs=1;
bool vs[250];

void call(long p)
{
	if(vs[p]==0)
		return ;
	vs[p]=0;

	for(long i=0;i<vc[p].size();i++)
		if(vs[vc[p][i]])
			call(vc[p][i]);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
			scanf("%ld",&bs[i]),dist[i]=100000000,vc[i].clear(),vs[i]=1;
		dist[1]=0;

		scanf("%ld",&m);

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&u[i],&v[i]);
			vc[u[i]].push_back(v[i]);
			cst[i]=(bs[v[i]]-bs[u[i]])*(bs[v[i]]-bs[u[i]])*(bs[v[i]]-bs[u[i]]);
		}

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(dist[v[j]]>dist[u[j]]+cst[j] && dist[u[j]]<100000000)
					dist[v[j]]=dist[u[j]]+cst[j];
		
		for(i=0;i<m;i++)
			if(dist[v[i]]>dist[u[i]]+cst[i] && dist[u[i]]<100000000)
				dist[v[i]]=-100000000,call(v[i]);

		scanf("%ld",&q);

		printf("Case %ld:\n",cs++);

		while(q--)
		{
			scanf("%ld",&des);
			if(dist[des]<3 || dist[des]==100000000)
				printf("?\n");
			else
				printf("%ld\n",dist[des]);
		}
	}
	return 0;
}