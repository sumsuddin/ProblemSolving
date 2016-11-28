#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
queue<long>que;
vector<long>vc[550];
vector<long>par[30050];
long i,m,n,b,a,l,sum,p;
bool vst[550],sst[30050];
void bfs()
{
	sst[0]=0;
	for(i=0;i<par[0].size();i++)
	{
		que.push(par[0][i]);
		vst[par[0][i]]=0;
	}

	while(!que.empty())
	{
		p=que.front();
		que.pop();
		for(i=0;i<vc[p].size();i++)
		{
			if(sst[vc[p][i]])
			{
				sum++;

				for(m=0;m<par[vc[p][i]].size();m++)
				{
					if(vst[par[vc[p][i]][m]])
					{
						vst[par[vc[p][i]][m]]=0;
						que.push(par[vc[p][i]][m]);
					}
				}

				sst[vc[p][i]]=0;
			}
		}
	}
}

int main()
{
	while(scanf("%ld%ld",&n,&m) && (n|| m))
	{
		for(i=0;i<=n;i++)
			sst[i]=1;
		l=m;
		while(m--)
		{
			vst[m]=1;
			scanf("%ld",&a);
			while(a--)
			{
				scanf("%ld",&b);
				par[b].push_back(m);
				vc[m].push_back(b);
			}
		}
		sum=1;
		sst[0]=0;
		if(par[0].size())
			bfs();
		printf("%ld\n",sum);
		for(i=0;i<=n;i++)
			par[i].clear();
		for(i=0;i<l;i++)
			vc[i].clear();
	}
	return 0;
}