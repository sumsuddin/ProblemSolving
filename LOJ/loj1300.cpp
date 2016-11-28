#include<stdio.h>
#include<vector>
#include<map>
#define MS 10000+500
using namespace std;
long dfn[MS],L[MS],vis[MS],tim,n,m,ans,i,par[MS],t,a,b,fl,cs=1;
vector<long>vc[MS];
map<long,long>mp[MS];
long dfs(long p)
{
	vis[p]=0;
	dfn[p]=L[p]=++tim;

	long i,d,ll;
	for(i=0;i<vc[p].size();i++)
	{
		d=vc[p][i];

		if(par[p]==d)
		continue;

		if(vis[d])
        {
            par[d]=p;
            ll=dfs(d);

            if(ll>dfn[p])
            mp[p][d]=1,mp[d][p]=1;

            if(ll<L[p])
            L[p]=ll;
        }
		else if(dfn[d]<L[p])
			L[p]=dfn[d];
	}
	return L[p];
}
void call(long n,long tim)
{
    vis[n]=0;
    dfn[n]=tim;
    m++;
    long d,i;

    for(i=0;i<vc[n].size();i++)
    {
        d=vc[n][i];

        if(par[n]==d || mp[n][d]==1 ||mp[d][n]==1)
        continue;

        par[d]=n;

        if(vis[d])
        call(d,dfn[n]+1);
        else
        {
            if((dfn[n]-dfn[d])%2==0)
            fl=1;
        }
    }
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
	    tim=0;
		scanf("%ld%ld",&n,&m);

		for(i=0;i<=n;i++)
			mp[i].clear(),vc[i].clear(),dfn[i]=L[i]=0,vis[i]=1,par[i]=-1;

		for(i=0;i<m;i++)
			scanf("%ld%ld",&a,&b),vc[a].push_back(b),vc[b].push_back(a);

		for(i=0;i<n;i++)
		{
			if(vis[i])
				dfs(i);
		}

		for(i=0;i<=n;i++)
		vis[i]=1,par[i]=-1,dfn[i]=0;

		ans=0;
		for(i=0;i<n;i++)
		{
		    if(vis[i])
		    {
		        fl=m=0;
		        call(i,1);
		        if(fl)
		        ans+=m;
		    }
		}
		printf("Case %ld: %ld\n",cs++,ans);
	}
	return 0;
}
