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


#define INF (1<<30)
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
long m,n,a[100050],flag,com[100050],i;
long search(long l,long h)
{
	long mid;
	while(l<h)
	{
		flag=0;
		mid=(l+h)/2;
		for(i=mid;i<=n;i++)
		{
			if(com[i]-com[i-mid]>=m)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			if(l+1==h)
				return l;

			h=mid;
		}
		else
		{
			if(l+1==h)
			{
				flag=0;
				for(i=h;i<=n;i++)
				{
					if(com[i]-com[i-h]>=m)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					return h;
				else
					return 0;
			}
			l=mid;
		}
	}
	return 0;
}

int main()
{
	while(~S2(n,m))
	{
		repl(i,n)
			S1(a[i]);

		flag=0;
		repl(i,n)
		{
			if(a[i]>m)
			{
				flag=1;
				break;
			}
			com[i]=com[i-1]+a[i];
		}
		if(flag)
			printf("1\n");
		else
		{
			printf("%ld\n",search(1,n));
		}
	}
    return 0;
}
