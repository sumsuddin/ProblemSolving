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

long i,n,t,cnt,s,cs=1,a;
int main()
{
	S1(t);
	while(t--)
	{
		cnt=0;s=0;
		S1(n);
		rep(i,n)
		{
			S1(a);
			s^=a;
			if(a>1)
				cnt++;
		}

		if(cnt==1)
			printf("Case %ld: Alice\n",cs++);
		else if(cnt==0)
		{
			if(s==0)
				printf("Case %ld: Alice\n",cs++);
			else
				printf("Case %ld: Bob\n",cs++);
		}
		else
		{
			if(s)
				printf("Case %ld: Alice\n",cs++);
			else
				printf("Case %ld: Bob\n",cs++);
		}
	}
    return 0;
}
