#include<stdio.h>
#include<map>
using namespace std;

map<long long,long long>mp;
map<long long ,long long>::iterator it;
long long cs=1;
long long rec(long long n)
{
    it=mp.find(n);
    if(it!=mp.end())
    return mp[n];

    if(n<3LL)
    return mp[n]=0LL;
    n--;
    long long a;
    a=rec(n/2LL)+rec(n/2LL+n%2LL)+(n/2LL);

    return mp[n+1LL]=a;
}

int main()
{
    long long t,n;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        printf("Case %lld: %lld\n",cs++,rec(n));
    }

    return 0;
}
