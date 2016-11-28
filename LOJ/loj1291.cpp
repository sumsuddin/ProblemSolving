#include<stdio.h>
#include<vector>
using namespace std;
long i,n,m,L[10050],dfn[10050],a,b,time,par[10050],ans,t,cs=1;
vector<long>vc[10050],chld[10050],bkeg[10050],chk[10050];
bool vst[10050];
void dfs(long p)
{
	long i,d,mn;

	for(i=0;i<vc[p].size();i++)
	{
		d=vc[p][i];
		if(vst[d])
		{
			par[d]=p;

			vst[d]=0;
			dfn[d]=time++;
			chld[p].push_back(d);
			dfs(d);
		}
		else if(d!=par[p])
			bkeg[d].push_back(p),bkeg[p].push_back(d);
	}
	mn=dfn[p];

	for(i=0;i<chld[p].size();i++)
	{
		d=chld[p][i];
		if(L[d]<mn)
			mn=L[d];
	}
	for(i=0;i<bkeg[p].size();i++)
	{
		d=bkeg[p][i];
		if(dfn[d]<mn)
			mn=dfn[d];
	}
	L[p]=mn;

	if(par[p]>=0)
	{
		if(L[p]>dfn[par[p]])
			L[p]=0,ans++;
	}
	else if(vc[p].size()==1)
		ans++;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=0;i<=n;i++)
			vst[i]=1,vc[i].clear(),bkeg[i].clear(),chld[i].clear();
		for(i=0;i<m;i++)
			scanf("%ld%ld",&a,&b),vc[a].push_back(b),vc[b].push_back(a);

		time=1;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(vst[i])
			{
				dfn[i]=time++;
				vst[i]=0;
				par[i]=-1;
				dfs(i);
			}
		}
		printf("Case %ld: %ld\n",cs++,ans%2+ans/2);
	}
	return 0;
}