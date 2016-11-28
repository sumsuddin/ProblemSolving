#include<stdio.h>
#include<vector>
using namespace std;
long i,n,m,L[1000],dfn[1000],a,b,time,par[1000],PP,tan,ans;
vector<long>vc[1000],chld[1000],bkeg[1000],chk[1000];
char c;
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
			dfn[d]=time++;
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
			ans++;
	}
}

int main()
{
	while(scanf("%ld",&n) && n)
	{
		for(i=1;i<=n;i++)
			vst[i]=1,vc[i].clear(),bkeg[i].clear(),chld[i].clear();
		for(i=0;i<m;i++)
			scanf("%ld%ld",&a,&b),vc[a].push_back(b),vc[b].push_back(a);

		while(scanf("%ld",&a) && a)
		{
			while(scanf("%ld%c",&b,&c))
			{
				vc[a].push_back(b),vc[b].push_back(a);
				if( c=='\n')
					break;
			}

		}

		ans=0;
		time=1;
		for(i=1;i<=n;i++)
		{
			if(vst[i])
			{
				dfn[i]=time++;
				vst[i]=0;
				par[i]=0;
				tan=0;
				PP=i;
				dfs(i);
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}