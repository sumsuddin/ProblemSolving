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
#define pii pair<int,int>
#define pmp make_pair


#define S1(x) scanf("%ld",&x)
#define S2(x,y) scanf("%ld%ld",&x,&y)
#define Ss(x) scanf("%s",x)

using namespace std;




//typedef long long i64;
//typedef unsigned long long ui64;

#define READ(aaaaai) freopen(aaaaai, "r", stdin)
#define WRITE(aaaaao) freopen(aaaaao, "w", stdout)

long count(long n)
{
	return (n*(n+1))/2;
}
long r1,r2,c1,c2,cs=1,t;
int main()
{
	S1(t);
	while(t--)
	{
		S2(r1,c1);
		S2(r2,c2);

		if(r1+c1==r2+c2)
			printf("Case %ld: %ld\n",cs++,r2-r1);
		else
			printf("Case %ld: %ld\n",cs++,c1+count(r2+c2)-count(r1+c1+1)+(r2+1));
	}
    return 0;
}
