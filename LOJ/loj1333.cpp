#include<stdio.h>
#include<algorithm>
using namespace std;
long long r,c,k,q,i,j,d,dd,M=1000000000LL,t,ans,cs=1LL,k1,k2;
struct ss
{
    long long x,y;
}
sr[1000050];

long long powr(long long b,long long p)
{
    if(p<=0LL || b==0)
    return 1LL;

    long long l=powr(b,p>>1);

    l=(l*l)%M;

    if(p&1)
    l=(l*b)%M;

    return l;
}

bool cmp(ss a,ss b)
{
    if(a.y==b.y)
    return a.x<b.x;
    else
    return a.y<b.y;
}

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ans=1LL;
        k1=k2=0LL;
        scanf("%lld%lld%lld%lld",&r,&c,&k,&q);
        for(i=0;i<q;i++)
        scanf("%lld%lld",&sr[i].x,&sr[i].y);

        sort(sr,sr+q,cmp);
        j=0;

        for(i=1;i<=c;i++)
        {
            dd=0LL;
            while(sr[j].y==i && j<q)
            {
                d=sr[j].x-dd-1LL;
                if(d>0)
                k1++,d--;
                if(d<0)
                d=0;
                k2+=d;
                dd=sr[j].x;
                j++;
            }
            d=r-dd;
            if(d>0)
            k1++,d--;
            if(d<0)
            d=0;
            k2+=d;
        }
        ans=(powr(k,k1)*powr(k-1,k2))%M;
        printf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;
}
