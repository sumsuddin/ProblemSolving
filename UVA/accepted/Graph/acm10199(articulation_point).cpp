#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<string,long>mp;
vector<long>vc[110],bkeg[110],chld[110];
struct ss
{
	bool f;
	char st[50];
}
sl[110];
long i,dfn[110],L[110],tim,cs=1,ans,par[110],PP,tan,n,a,b,m;
char sr[50],sy[50];
bool sstt=0;
bool cmp(ss a,ss b)
{
	if(strcmp(a.st,b.st)<=0)
		return 1;
	else
		return 0;
}

bool vst[1000];
void dfs(long p)
{
	long i,d,mn;

	for(i=0;i<vc[p].size();i++)
	{
		d=vc[p][i];
		par[d]=p;
		if(vst[d])
		{
			if(p==PP)
				tan++;

			vst[d]=0;
			dfn[d]=tim++;
			chld[p].push_back(d);
			dfs(d);
		}
		else if(d!=par[p])
			bkeg[d].push_back(p),bkeg[p].push_back(d);
	}
	mn=dfn[p];
	bool art=0;

	for(i=0;i<chld[p].size();i++)
	{
		d=chld[p][i];
		if(L[d]<mn)
			mn=L[d];

		if(L[d]>=dfn[p])
			art=1;
	}
	for(i=0;i<bkeg[p].size();i++)
	{
		d=bkeg[p][i];
		if(dfn[d]<mn)
			mn=dfn[d];
	}
	L[p]=mn;
	if(art)
	{
		if(p!=PP || (p==PP && tan>1))
		{
			sl[p].f=1;
			ans++;
		}
	}
}

int main()
{
	while(~scanf("%ld",&n) && n)
	{
		if(sstt)
			printf("\n");
		else
			sstt=1;
		for(i=0;i<n;i++)
		{
			vst[i]=1;
			vc[i].clear();
			bkeg[i].clear();
			chld[i].clear();

			scanf("%s",sl[i].st);
			mp[sl[i].st]=i;
			sl[i].f=0;
		}
		scanf("%ld",&m);

		while(m--)
		{
			scanf("%s%s",sr,sy);

			a=mp[sr];
			b=mp[sy];

			vc[a].push_back(b);
			vc[b].push_back(a);
		}

		tim=1;
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(vst[i])
			{
				dfn[i]=tim++;
				vst[i]=0;
				par[i]=0;
				tan=0;
				PP=i;
				dfs(i);
			}
		}
		printf("City map #%ld: %ld camera(s) found\n",cs++,ans);
		sort(sl,sl+n,cmp);
		for(i=0;i<n;i++)
			if(sl[i].f)
				printf("%s\n",sl[i].st);

		mp.clear();
	}
	return 0;
}
