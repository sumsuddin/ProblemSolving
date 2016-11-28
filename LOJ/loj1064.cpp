#include<stdio.h>
#include<map>
using namespace std;
map<long long ,long long >mp[30];
map<long long ,long long >:: iterator it;
long long n,k,t,i,g,cs=1;

long long gcd(long long a,long long b)
{
    long long c=a%b;
    while(c)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

long long powr(long long b,long long x)
{
	if(x<0)
		return 0;
	long long ret=1LL;
	while(x--)
		ret*=b;
	return ret;
}

long long rec(long long x,long long sum)
{
	if(x==n)
	{
		if(sum>=k)
			return 1LL;
		else
			return 0LL;
	}
	it=mp[x].find(sum);
	if(it!=mp[x].end())
		return mp[x][sum];

	long long i,ret=0;
	for(i=1LL;i<=6LL;i++)
		ret+=rec(x+1LL,sum+i);

	mp[x][sum]=ret;

	return ret;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		
		for(i=0LL;i<=n;i++)
			mp[i].clear();
		
		i=rec(0LL,0LL);
		n=powr(6LL,n);
		g=gcd(i,n);
		i/=g;
		n/=g;
		if(i==0)
		printf("Case %lld: 0\n",cs++);
		else if(i==n)
		printf("Case %lld: 1\n",cs++);
		else
		printf("Case %lld: %lld/%lld\n",cs++,i,n);
	}
	return 0;
}
