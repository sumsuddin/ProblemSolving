#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<long>vc[10050],chld[10050],bkeg[10050];
bool vst[10050];
long i,j,par[1000050],L[10050],dfn[10050],a,b,time,PP,tan,n,ans,m,lst,t,cs=1;
struct ss
{
	long fir,sec;
}
sr[100050];

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

	for(i=0;i<chld[p].size();i++)
	{
		d=chld[p][i];
		if(L[d]<mn)
			mn=L[d];

		if(L[d]>dfn[p])
		{
			a=d;
			b=p;
			if(a>b)
			{
				m=a;
				a=b;
				b=m;
			}
			sr[lst].fir=a;
			sr[lst++].sec=b;
			ans++;
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
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			vc[i].clear(),bkeg[i].clear(),chld[i].clear();
			vst[i]=1;
			scanf("%ld (%ld)",&a,&m);

			for(j=0;j<m;j++)
				scanf("%ld",&b),vc[a].push_back(b);
		}


		time=1;ans=lst=0;
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
		printf("Case %ld:\n%ld critical links\n",cs++,ans);

		sort(sr,sr+lst,cmp);

		for(i=0;i<lst;i++)
			printf("%ld - %ld\n",sr[i].fir,sr[i].sec);
	}
	return 0;
}