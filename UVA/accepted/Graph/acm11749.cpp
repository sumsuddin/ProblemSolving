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

struct ss
{
	long p,q,w;
}
sr[1000055];

long i,m,mx,n,sum;
vector<long>vc[1000];
bool vst[1000];
void dfs(long p)
{
	vst[p]=0;
	for(long i=0;i<vc[p].size();i++)
	{
		if(vst[vc[p][i]])
		{
			sum++;
			vst[vc[p][i]]=0;
			dfs(vc[p][i]);
		}
	}
}

int main()
{
	while(~S2(n,m) && (m|| n))
	{
		for(i=0;i<=n;i++)
			vc[i].clear(),vst[i]=1;

		for(i=0;i<m;i++)
		{
			S3(sr[i].p,sr[i].q,sr[i].w);
			if(i==0)
				mx=sr[i].w;

			if(sr[i].w>mx)
				mx=sr[i].w;
		}
		while(m--)
		{
			if(sr[m].w==mx)
			{
				vc[sr[m].p].push_back(sr[m].q);
				vc[sr[m].q].push_back(sr[m].p);
			}
		}
		mx=0;
		for(i=1;i<=n;i++)
		{
			sum=1;
			if(vst[i])
				dfs(i);
			if(mx<sum)
				mx=sum;
		}
		printf("%ld\n",mx);
	}
    return 0;
}
