#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[30000];
long n,t,i,u,v,color[30000],mm[5],mx,cs=1,sum;
bool vst[30000];
void dfs(long n,long cl)
{
	color[n]=cl;

	long i;
	for(i=0;i<vc[n].size();i++)
	{
		if(vst[vc[n][i]])
		{
			mm[!cl]++;
			vst[vc[n][i]]=0;
			dfs(vc[n][i],!cl);
			vc[vc[n][i]].clear();
		}
	}
}


int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<=20000;i++)
			color[i]=-1;

		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&u,&v);

			vc[u].push_back(v);
			vc[v].push_back(u);

			vst[u]=1;
			vst[v]=1;
		}
		sum=0;
		for(i=1;i<=20000;i++)
		{
			if(vst[i])
			{
				mx=0;
				mm[0]=mm[1]=0;
				vst[i]=0;
				mm[0]++;
				dfs(i,0);
				vc[i].clear();
				if(mm[0]>mx)
					mx=mm[0];
				if(mm[1]>mx)
					mx=mm[1];
				sum+=mx;
			}
		}
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}
