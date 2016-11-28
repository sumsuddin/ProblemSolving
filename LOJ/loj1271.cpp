#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<long>vc[50050];
queue<long>que;
long i,p,par[50050],t,n,a,b,end,strt,cs=1;
bool vst[50050];
void bfs()
{
	par[strt]=-1;
	que.push(strt);
	vst[strt]=0;
	long i;
	while(!que.empty())
	{
		p=que.front();
		que.pop();


		for(i=0;i<vc[p].size();i++)
			if(vst[vc[p][i]])
			{
				par[vc[p][i]]=p;
				vst[vc[p][i]]=0;

				if(vc[p][i]==end)
				{
					while(!que.empty())
						que.pop();
					p=vc[p][i];
					while(p>0)
						vc[0].push_back(p),p=par[p];
					break;
				}

				que.push(vc[p][i]);
			}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<50001;i++)
			vst[i]=0,vc[i].clear();

		scanf("%ld",&a);
		strt=a;
		vst[a]=1;
		for(i=1;i<n;i++)
		{
			scanf("%ld",&b);
			vc[a].push_back(b);
			vc[b].push_back(a);
			vst[b]=1;
			a=b;
		}
		end=b;
		for(i=0;i<50001;i++)
			if(vst[i])
				sort(vc[i].begin(),vc[i].end());
		bfs();
		printf("Case %ld:\n",cs++);
		a=vc[0].size();
		printf("%ld",vc[0][a-1]);
		for(i=a-2;i>=0;i--)
			printf(" %ld",vc[0][i]);
		printf("\n");
	}
	return 0;
}