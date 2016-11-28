#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[1050];
long i,t,n,m,z[1050],o[1050],a,b,sum,cs=1;
bool vis[1050];

void rec(long a)
{
	vis[a]=0;
	if(vc[a].size()==1 && vis[vc[a][0]]==0)
	{
		z[a]=0;
		o[a]=1;
		return;
	}

	long i;
	for(i=0;i<vc[a].size();i++)
	{
		if(vis[vc[a][i]])
		{
			rec(vc[a][i]);
			z[a]+=(z[vc[a][i]]>o[vc[a][i]])?z[vc[a][i]]:o[vc[a][i]];
			o[a]+=z[vc[a][i]];
		}
	}
	o[a]++;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=1;i<=n;i++)
			vis[i]=1,z[i]=o[i]=0,vc[i].clear();

		sum=0;
		while(m--)
		{
			scanf("%ld%ld",&a,&b);
			vc[a].push_back(b);
			vc[b].push_back(a);
		}

		for(i=1;i<=n;i++)
			if(vis[i])
			{
				rec(i);
				sum+=z[i]>o[i]?z[i]:o[i];
			}

		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}