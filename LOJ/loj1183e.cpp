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


#define S1(x) scanf("%lld",&x)
#define S2(x,y) scanf("%lld%lld",&x,&y)
#define S3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define Ss(x) scanf("%s",x)

using namespace std;

//typedef long long long long i64;
//typedef unsigned long long long long ui64;

#define READ(aaaaai) freopen(aaaaai, "r", stdin)
#define WRITE(aaaaao) freopen(aaaaao, "w", stdout)

long i,lft[1000005],rht[1000005],t,n,p,q,cs=1,pr[1000005],ts[1000005],e,dir;
bool prs[1000005];
long long vlu,g;
void build(long l,long h,long pos)
{
	lft[pos]=l;rht[pos]=h;
	if(l==h)
		pr[pos]=ts[pos]=prs[pos]=0;
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		pr[pos]=ts[pos]=prs[pos]=0;
	}
}

void update(long l,long h,long pos,long long vlu)
{
	if(h<lft[pos] || l>rht[pos])
		return;
	else if(l<=lft[pos] && h>=rht[pos])
	{
		prs[pos]=1;
		pr[pos]=vlu;
		ts[pos]=vlu*(rht[pos]-lft[pos]+1);
	}
	else
	{
		if(prs[pos])
		{
			prs[pos]=0;

			prs[pos*2]=1;
			pr[pos*2]=pr[pos];
			ts[pos*2]=pr[pos]*(rht[pos*2]-lft[pos*2]+1);

			prs[pos*2+1]=1;
			pr[pos*2+1]=pr[pos];
			ts[pos*2+1]=pr[pos]*(rht[pos*2+1]-lft[pos*2+1]+1);
		}
		update(l,h,pos*2,vlu);
		update(l,h,pos*2+1,vlu);

		ts[pos]=ts[pos*2]+ts[pos*2+1];
	}
}

long long range(long l,long h,long pos)
{
	if(h<lft[pos] || l>rht[pos])
		return 0;
	else if(l<=lft[pos] && h>=rht[pos])
		return ts[pos];
	else
	{
		if(prs[pos])
		{
			prs[pos]=0;

			prs[pos*2]=1;
			pr[pos*2]=pr[pos];
			ts[pos*2]=pr[pos]*(rht[pos*2]-lft[pos*2]+1);

			prs[pos*2+1]=1;
			pr[pos*2+1]=pr[pos];
			ts[pos*2+1]=pr[pos]*(rht[pos*2+1]-lft[pos*2+1]+1);
		}

		return range(l,h,pos*2)+range(l,h,pos*2+1);
	}
}
long long gcd(long long a,long long b)
{
	long long c;
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
				vlu=range(p,q,1);
				if(vlu)
				{
   				g=gcd(vlu,(q-p+1));
   				vlu/=g;
   				g=(q-p+1)/g;
   				if(g==1)
   					printf("%lld\n",vlu);
   				else
   					printf("%lld/%lld\n",vlu,g);
            }
            else
               printf("0\n");
               
			}
			else
			{
				scanf("%lld",&vlu);
				update(p,q,1,vlu);
			}
		}
	}
    return 0;
}
