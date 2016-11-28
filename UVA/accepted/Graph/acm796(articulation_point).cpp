#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<long>vc[12000],chld[12000],bkeg[12000];
bool vst[1000150];
long i,j,par[12000],L[12000],dfn[12000],a,b,tim,n,m,lst;
struct ss
{
	long fir,sec;
}
sr[100150];

bool cmp(ss a,ss b)
{
	if(a.fir==b.fir)
		return a.sec<b.sec;
	else
		return a.fir<b.fir;
}

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
			dfn[d]=tim++;
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

		if(L[d]>dfn[p])
		{
			if(d<p)
			{
				sr[lst].fir=d;
				sr[lst++].sec=p;
			}
			else
			{
				sr[lst].fir=p;
				sr[lst++].sec=d;
			}
		}
	}
	for(i=0;i<bkeg[p].size();i++)
	{
		d=bkeg[p][i];
		if(dfn[d]<mn)
			mn=dfn[d];
	}
	L[p]=mn;
}

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
		{
			vc[i].clear(),bkeg[i].clear(),chld[i].clear();
			vst[i]=1;
			scanf("%ld (%ld)",&a,&m);

			for(j=0;j<m;j++)
				scanf("%ld",&b),vc[a].push_back(b),vc[b].push_back(a);
		}

		tim=1;lst=0;
		for(i=1;i<=n;i++)
		{
			if(vst[i])
			{
				dfn[i]=tim++;
				vst[i]=0;
				par[i]=-1;
				dfs(i);
			}
		}
		printf("%ld critical links\n",lst);

		sort(sr,sr+lst,cmp);

		for(i=0;i<lst;i++)
			printf("%ld - %ld\n",sr[i].fir,sr[i].sec);
		printf("\n");
	}
	return 0;
}
