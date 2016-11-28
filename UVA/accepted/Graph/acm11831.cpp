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

long i,j,dir,x[]={-1,0,1,0},y[]={0,1,0,-1},sum,r,c,t,flag;
char st[150][150],ch;

void front()
{
	if(i+x[dir]<r && i+x[dir]>=0 && j+y[dir]<c && j+y[dir]>=0  && st[i+x[dir]][j+y[dir]]!='#')
	{
		i+=x[dir];
		j+=y[dir];
		if(st[i][j]=='*')
			sum++,st[i][j]='.';
	}
}

void com()
{
	if(st[i][j]=='N')
		dir=0;
	else
		if(st[i][j]=='L')
			dir=1;
		else
			if(st[i][j]=='S')
				dir=2;
			else
				dir=3;
	getchar();
	while(t--)
	{
		scanf("%c",&ch);
		if(ch=='E')
		{
			dir--;
			if(dir<0)
				dir=3;
		}
		else
			if(ch=='D')
			{
				dir++;
				if(dir>3)
					dir=0;
			}
			else
				front();
	}
}

int main()
{
	while(~S3(r,c,t) && (r|| c|| t))
	{
		sum=0;flag=1;
		for(i=0;i<r;i++)
			Ss(st[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;st[i][j];j++)
			{
				if(st[i][j]=='N' || st[i][j]=='S' || st[i][j]=='L' || st[i][j]=='O')
				{
					com();
					flag=0;
					break;
				}
			}
			if(flag==0)
				break;
		}
		printf("%ld\n",sum);
	}
    return 0;
}
