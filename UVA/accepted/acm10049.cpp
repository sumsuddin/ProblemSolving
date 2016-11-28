#include<stdio.h>
#include<string.h>
long dp[1000050],i,n;
long x(long n);
long f(long n)
{
    if(n>700000)
    return 2000000005;

    if(n<=0)
    return 0;

    if(dp[n]>=0)
    return dp[n];

    if(n==1 || n==2)
    return dp[n]=n;

    return dp[n]=x(n-1)+f(n-1);
}

long x(long n)
{
    long h,l,mid;
    l=1;
    h=n+1;
    while(l<h)
    {
        mid=(l+h)/2;

        if(f(mid)<=n)
        l=mid+1;
        else
        h=mid;
    }

    return l-1;
}

int main()
{
    memset(dp,-1,sizeof(dp));

    for(i=1;i<700000;i++)
    f(i);

    while(~scanf("%ld",&n) && n)
    {
        printf("%ld\n",x(n));
    }
    return 0;
}
