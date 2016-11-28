#include<stdio.h>
long i,cs=1,n,mp[10000050],lst,last,rm[10000050],st[100];

void build(long a)
{
    long i;
    bool aa[11];

    for(i=1;i<10;i++)
    aa[i]=1;
    i=a;
    while(i)
    aa[i%10]=0,i/=10;

    for(i=1;i<10;i++)
    if(aa[i])
    mp[lst++]=a*10LL+(long)i;
}
bool chk(long n)
{
    long i=0,j,c;
    while(n)
    st[i++]=n%10,n/=10;
    n=i;

    for(i=0,j=n-1;i<(n>>1);i++,j--)
    {
        c=st[i];
        st[i]=st[j];
        st[j]=c;
    }

    for(i=0,j=0;i<n;i++)
    {
        c=j;
        j=(j+st[j])%n;
        if(st[c]==0)
        return 0;
        st[c]=0;
    }
    if(j)
    return 0;

    return 1;
}

long srch(long l,long h,long v)
{
    if(l>h)
    return last-1;

    if(l==h)
    return l;

    long mid=(l+h)>>1;

    if(rm[mid]>=v)
    return srch(l,mid,v);
    else
    return srch(mid+1,h,v);
}

int main()
{
    for(i=1;i<10;i++)
    mp[lst++]=(long)i;

    for(i=0;i<80000;i++)
    build(mp[i]);

    for(i=9;i<lst;i++)
    if(chk(mp[i]))
    rm[last++]=mp[i];


    while(scanf("%ld",&n) && n)
    printf("Case %ld: %ld\n",cs++,rm[srch(0,last-1,n)]);

    return 0;
}
