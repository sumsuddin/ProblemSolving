#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<long>vc[10050];
long mx,time,n,eg,p,q,i,t,cs=1;
bool vst[10050];

struct sss
{
	long ind,fin;
}sr[10050];


bool cmpr(sss a,sss b)
{
	if(a.fin>b.fin)
		return 1;
	else
		return 0;
}

void dfs(long a)
{
	long k;
	for(k=0;k<vc[a].size();k++)
		if(vst[vc[a][k]])
		{
			time++;
			vst[vc[a][k]]=0;
			dfs(vc[a][k]);
		}
	sr[a].fin=++time;
}

void dfs1(long a)
{
	long k;
	for(k=0;k<vc[a].size();k++)
	{
		if(vst[vc[a][k]])
			vst[vc[a][k]]=0,dfs1(vc[a][k]);
	}
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&eg);
		mx=0;
		for(i=1;i<=n;i++)
			sr[i].fin=0,vst[i]=1;

		for(i=0;i<eg;i++)
		{
			scanf("%ld%ld",&p,&q);
			vc[p].push_back(q);
		}
		time=0;
		for(i=1;i<=n;i++)
			if(vst[i])
				vst[i]=0,dfs(i);
		for(i=1;i<=n;i++)
			vst[i]=1,sr[i].ind=i;

		sort(sr+1,sr+n+1,cmpr);
		time=0;
		for(i=1;i<=n;i++)
		{
			if(vst[sr[i].ind])
			{
				time++;
				vst[sr[i].ind]=0;
				dfs1(sr[i].ind);
			}
		}

		printf("Case %ld: %ld\n",cs++,time);

		for(i=0;i<=n;i++)
			vc[i].clear();
	}
	return 0;
}