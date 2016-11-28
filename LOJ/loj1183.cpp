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

long i,prio[400005],up[400005],lft[400005],rht[400005],full[400005],t,n,e,p,q,vlu,dir,g,cs=1;

void build(long l,long h,long pos)
{
	lft[pos]=l;rht[pos]=h;
	if(l==h)
		up[pos]=0,full[pos]=0,prio[pos]=50001;
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		
		up[pos]=0;
		full[pos]=0;
		prio[pos]=50001;
	}
}

long update(long l,long h,long pos,long vlu,long e,long pb,long pr)
{
	if(pr>prio[pos])
	{
		pr=prio[pos];
		pb=full[pos];
	}

	if(h<lft[pos] || l>rht[pos])
		return up[pos]=(rht[pos]-lft[pos]+1)*pb;
	else if(l<=lft[pos] && h>=rht[pos])
	{
		full[pos]=vlu,up[pos]=vlu*(rht[pos]-lft[pos]+1);
		prio[pos]=e;
		return up[pos];
	}
	else
	{
		long nm;
		nm=update(l,h,pos*2,vlu,e,pb,pr);
		nm+=update(l,h,pos*2+1,vlu,e,pb,pr);
		
		up[pos]=up[pos*2]+up[pos*2+1];
		return up[pos];
	}
}

long range(long l,long h,long pos,long pb,long pr)
{
	if(h<lft[pos] || l>rht[pos])
		return 0;
	else if(l<=lft[pos] && h>=rht[pos])
	{
		if(pr<prio[pos])
			return (rht[pos]-lft[pos]+1)*pb;
		else
			return up[pos];
	}
	else
	{
		long nm;
		if(pr>prio[pos])
		{
			pr=prio[pos];
			pb=full[pos];
		}

		nm=range(l,h,pos*2,pb,pr);
		nm+=range(l,h,pos*2+1,pb,pr);
		return nm;
	}
}
long gcd(long a,long b)
{
	long c;
	while(1)
	{
		c=b%a;
		if(c==0)
			return a;
		b=a;
		a=c;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		build(0,n-1,1);
		printf("Case %ld:\n",cs++);
		while(e--)
		{
			scanf("%ld%ld%ld",&dir,&p,&q);
			if(dir==2)
			{
				dir=range(p,q,1,0,50002);
				if(dir%(q-p+1))
					g=gcd(dir,(q-p+1));
				else
					g=(q-p+1);

				if(q-p+1==g)
					printf("%ld\n",dir/g);
				else
					printf("%ld/%ld\n",dir/g,(q-p+1)/g);
			}
			else
			{
				scanf("%ld",&vlu);
				update(p,q,1,vlu,e,0,50002);
			}
		}
	}
    return 0;
}
