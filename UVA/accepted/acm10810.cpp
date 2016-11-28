#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
long long tree[4000050],name[4000050],n,ar[600050],br[600050],i,j,sum;
map<long long,long long>mp;

void build(long long l,long long h,long long pos)
{
    name[pos]=l;

    if(l==h)
    {
        tree[pos]=0;
        return;
    }
    build(l,(l+h)/2,pos*2);
    build((l+h)/2+1,h,pos*2+1);
    tree[pos]=tree[pos*2]+tree[pos*2+1];
}
long long rangeh(long long v,long long l,long long h,long long pos)
{
    if(v>=h)
    return 0;

    if(v<l)
    return tree[pos];

    return rangeh(v,l,(l+h)/2,pos*2)+rangeh(v,(l+h)/2+1,h,pos*2+1);
}

long long rangel(long long v,long long l,long long h,long long pos)
{
    if(l>=v)
    return 0;

    if(h<v)
    return tree[pos];

    return rangel(v,l,(l+h)/2,pos*2)+rangel(v,(l+h)/2+1,h,pos*2+1);
}

void update(long long v,long long l,long long h, long long pos)
{
    if(l==h)
    {
        if(l==v)
        tree[pos]++;

        return;
    }
    if((l+h)/2>=v)
    update(v,l,(l+h)/2,pos*2);
    else
    update(v,(l+h)/2+1,h,pos*2+1);
    tree[pos]=tree[pos*2]+tree[pos*2+1];
}

int main()
{
    while(~scanf("%lld",&n) && n)
    {
        mp.clear();
        for(i=0;i<n;i++)
        scanf("%lld",&ar[i]),br[i]=ar[i];

        sort(br,br+n);

        mp[br[0]]=0;
        for(i=1,j=0;i<n;i++)
        {
            if(br[i]!=br[i-1])
            j++;
            mp[br[i]]=j;
        }

        build(0,j,1);
        sum=0;

        for(i=0;i<n;i++)
        {
            sum+=rangeh(mp[ar[i]],0,j,1);
            update(mp[ar[i]],0,j,1);
        }

        printf("%lld\n",sum);
    }
    return 0;
}
