#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<long>vc[10050];
vector<long>vt[10050];
map<string,long>mp;
long tim,n,eg,p,q,i;
bool vst[10050];
char st[200];
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
			tim++;
			vst[vc[a][k]]=0;
			dfs(vc[a][k]);
		}
	sr[a].fin=++tim;
}

void dfs1(long a)
{
	long k;
	for(k=0;k<vt[a].size();k++)
	{
		if(vst[vt[a][k]])
			vst[vt[a][k]]=0,dfs1(vt[a][k]);
	}
}

int main()
{
	while(scanf("%ld%ld",&n,&eg),(n||eg))
	{
		getchar();
		for(i=1;i<=n;i++)
		{
			gets(st);
			mp[st]=i;
			sr[i].fin=0,vst[i]=1;
		}

		for(i=0;i<eg;i++)
		{
			gets(st);
			p=mp[st];
			gets(st);
			q=mp[st];

			vc[p].push_back(q);
			vt[q].push_back(p);
		}
		tim=0;
		for(i=1;i<=n;i++)
			if(vst[i])
				vst[i]=0,dfs(i);
		for(i=1;i<=n;i++)
			vst[i]=1,sr[i].ind=i;

		sort(sr+1,sr+n+1,cmpr);
		tim=0;
		for(i=1;i<=n;i++)
		{
			if(vst[sr[i].ind])
			{
				tim++;
				vst[sr[i].ind]=0;
				dfs1(sr[i].ind);
			}
		}

		printf("%ld\n",tim);

		mp.clear();
		for(i=0;i<=n;i++)
			vc[i].clear(),vt[i].clear();
	}
	return 0;
}
