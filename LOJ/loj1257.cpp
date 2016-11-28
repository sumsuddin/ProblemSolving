#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[30050],wt[30050];
long i,t,mx,mmx,mm,p,q,w,cs=1,dist[30050];
bool vst[30050];
void dfs(long sc,long dis)
{
	long i;
	if(dist[sc]<dis)
		dist[sc]=dis;
	if(dis>mmx)
		mmx=dis,mm=sc;
	for(i=0;i<vc[sc].size();i++)
	{
		w=vc[sc][i];
		if(vst[vc[sc][i]])
		{
			vst[vc[sc][i]]=0;
			dfs(vc[sc][i],dis+wt[sc][i]);
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&mx);

		dist[0]=0;
		for(i=1;i<mx;i++)
		{
			dist[i]=0;
			scanf("%ld%ld%ld",&p,&q,&w);
			vc[p].push_back(q);
			wt[p].push_back(w);
			vc[q].push_back(p);
			wt[q].push_back(w);
		}
		for(i=0;i<=mx;i++)
			vst[i]=1;
		mmx=0;
		vst[1]=0;
		mm=1;
		dfs(1,0);

		for(i=0;i<=mx;i++)
			vst[i]=1;

		vst[mm]=0;
		dfs(mm,0);

		for(i=0;i<=mx;i++)
			vst[i]=1;
		vst[mm]=0;
		dfs(mm,0);

		printf("Case %ld:\n",cs++);
		for(i=0;i<mx;i++)
			printf("%ld\n",dist[i]),vc[i].clear(),wt[i].clear();
		vc[mx].clear();
		wt[mx].clear();
	}
	return 0;
}