#include<stdio.h>
long prs,dp[15][100][100],vst[15][100][100],l,h,k,t;

long rec(long l,long s1,long s2)
{
    if(l<-1)
    return 0;

    if(l<0)
    if(s1%k==0 && s2%k==0)
    return 1;
    else
    return 0;

    if(vst[l][s1][s2]==prs)
    return dp[l][s1][s2];

    vst[l][s1][s2]=prs;
    dp[l][s1][s2]=0;
    long i;
    for(i=0;i<10;i++)
    dp[l][s1][s2]+=rec(l-1,(s1+i)%k,(s2*10+i)%k);

    return dp[l][s1][s2];
}

long make(long n)
{
    if(n==0)
    return 1;

    long d=1,l=0,ans=0,s1,s2;
    while(d<=n)
    {
        ans+=rec(l-1,0,0)-rec(l-2,0,0);
        d*=10,l++;
    }
    d/=10,l--;
    for(long i=1;i<n/d;i++)
    ans+=rec(l-1,i,i);
    s1=s2=(n/d)%k;
    n%=d;
    d/=10;
    l--;

    while(l>=0)
    {
        for(long i=0;i<n/d;i++)
        ans+=rec(l-1,(s1+i)%k,(s2*10+i)%k);

        s1+=n/d;
        s2=s2*10+n/d;
        s1%=k;
        s2%=k;

        n%=d;
        d/=10;
        l--;
    }
    ans+=rec(l,s1,s2);
    return ans;
}

int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        prs++;
        scanf("%ld%ld%ld",&l,&h,&k);
        if(k>90)
        l=0;
        else
        l=make(h)-make(l-1);

        printf("Case %ld: %ld\n",prs,l);
    }
    return 0;
}
