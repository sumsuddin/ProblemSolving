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
} sr[300000];
long i,n,m,a[150],rank[150],tot,p1,p2,t,s,cs=1;
int cmp(ss a,ss b)
{
	if(a.w>b.w)
		return 0;
	else
		return 1;
}


void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}
long mst(long i,long eg,long j)
{
	tot=0;
	for(i=i;i!=eg;i+=j)
	{
		p1=parent(sr[i].p);
		p2=parent(sr[i].q);
		if(p1!=p2)
		{
			if(rank[p1]>rank[p2])
			{
				a[p2]=p1;
				rank[p1]++;
			}
			else
			{
				a[p1]=p2;
				rank[p2]++;
			}
			tot+=sr[i].w;
		}
	}
	return tot;
}

int main()
{
	S1(t);
	while(t--)
	{
		S1(n);
		i=0;
		while(scanf("%ld%ld%ld",&sr[i].p,&sr[i].q,&sr[i].w) && (sr[i].p || sr[i].q || sr[i].w))
			i++;

		m=i+1;

		s=0;
		sort(sr,sr+m,cmp);
		init();
		s=mst(0,m,1);
		init();
		s+=mst(m-1,-1,-1);
		if(s%2==0)
			printf("Case %ld: %ld\n",cs++,s/2);
		else
			printf("Case %ld: %ld/2\n",cs++,s);
	}
    return 0;
}
