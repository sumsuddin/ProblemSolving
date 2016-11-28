#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<long>vc[150];
vector<long>vt[150];
long tim,n,eg,p,q,i,kk,cs=1;
bool vst[150];
char st[150],sy[150][150];
map<string,long>mp;
struct sss
{
	long ind,fin;
}sr[150];


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
		{
			vst[vt[a][k]]=0,dfs1(vt[a][k]);
			printf(", %s",sy[vt[a][k]]);
		}
	}
}

int main()
{
	while(scanf("%ld%ld",&n,&eg),(n||eg))
	{
		getchar();
		for(i=1;i<=n;i++)
			sr[i].fin=0,vst[i]=1;

		kk=1;
		for(i=0;i<eg;i++)
		{
			scanf("%s",st);
			if(mp[st]==0)
			{
				strcpy(sy[kk],st);
				mp[st]=kk++;
			}
			p=mp[st];
		
			scanf("%s",st);
			if(mp[st]==0)
			{
				strcpy(sy[kk],st);
				mp[st]=kk++;
			}
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
		if(cs>1)
			printf("\n");
		printf("Calling circles for data set %ld:\n",cs++);
		for(i=1;i<=n;i++)
		{
			if(vst[sr[i].ind])
			{
				printf("%s",sy[sr[i].ind]);
				vst[sr[i].ind]=0;
				dfs1(sr[i].ind);
				printf("\n");
			}
		}

		mp.clear();

		for(i=0;i<=n;i++)
			vc[i].clear(),vt[i].clear();
	}
	return 0;
}