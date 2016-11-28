#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define stream istringstream
#define rep(i,n) for(i=0; i<n; i++)
#define repv(i,n) for(i=n-1; i>=0; i--)
#define repl(i,n) for(i=1; i<=n; i++)
#define replv(i,n) for(i=n; i>=1; i--)


#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9


#define S1(x) scanf("%ld",&x)
#define S2(x,y) scanf("%ld%ld",&x,&y)
#define S3(x,y,z) scanf("%ld%ld%ld",&x,&y,&z)
#define Ss(x) scanf("%s",x)

using namespace std;

//typedef long long i64;
//typedef unsigned long long ui64;

#define READ(aaaaai) freopen(aaaaai, "r", stdin)
#define WRITE(aaaaao) freopen(aaaaao, "w", stdout)
map<string,long>mp;
long i,n,m,cs=1,t,p1,p2,tot,sum,rank[100000],par[100000];
char st[105],sy[105];
struct ss
{
	long p,q,w;
}
sr[100000];

bool cmp(ss a,ss b)
{
	if(a.w>b.w)
		return 0;
	else
		return 1;
}

long parent(long p)
{
	if(par[p]!=p)
		par[p]=parent(par[p]);
	return par[p];
}

int main()
{
	S1(t);
	while(t--)
	{
		n=1;
		S1(m);
		for(i=0;i<m;i++)
		{
			scanf("%s%s%ld",st,sy,&sr[i].w);
			if(mp[st]==0)
				mp[st]=n++;
			if(mp[sy]==0)
				mp[sy]=n++;
			sr[i].p=mp[st];
			sr[i].q=mp[sy];
		}
		for(i=1;i<=n;i++)
			rank[i]=0,par[i]=i;
		sort(sr,sr+m,cmp);
		tot=sum=0;
		for(i=0;i<m;i++)
		{
			p1=parent(sr[i].p);
			p2=parent(sr[i].q);
			if(p1!=p2)
			{
				if(rank[p2]>rank[p1])
				{
					par[p1]=p2;
					rank[p2]++;
				}
				else
				{
					par[p2]=p1;
					rank[p1]++;
				}
				sum+=sr[i].w;
				tot++;
			}
		}
		if(tot==n-2)
			printf("Case %ld: %ld\n",cs++,sum);
		else
			printf("Case %ld: Impossible\n",cs++);
		mp.clear();
	}
    return 0;
}
