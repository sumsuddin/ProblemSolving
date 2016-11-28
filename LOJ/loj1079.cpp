#include<stdio.h>
long vst[105][10050],t,n,inf=1000009,prs,m[105],i;
double dp[105][10050],pr[105],P;

double fn(long n,long sum)
{
    if(sum<=0)
    return 0;

    if(n<0)
    return inf;

    if(vst[n][sum]==prs)
    return dp[n][sum];

    vst[n][sum]=prs;

    dp[n][sum]=(fn(n-1,sum-m[n])*(1.0-pr[n]))+pr[n]+1e-9;

    if(dp[n][sum]-fn(n-1,sum)>1e-9)
    dp[n][sum]=fn(n-1,sum);

    return dp[n][sum];
}

long bsearch(long l,long h)
{
    long mid=(l+h)>>1;

    if(l==h)
    return l;

    if(l+1==h)
    if(P-fn(n-1,h)>1e-6)
    return h;
    else
    return l;

    if(P-fn(n-1,mid)>1e-6)
    return bsearch(mid,h);
    else
    return bsearch(l,mid);
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%lf%ld",&P,&n);
        prs++;

        for(i=0;i<n;i++)
        scanf("%ld%lf",&m[i],&pr[i]);

        printf("Case %ld: %ld\n",prs,bsearch(0,10000));
    }
    return 0;
}
