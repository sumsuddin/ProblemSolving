#include<stdio.h>
long long musk[1000000],i,j,a,t,n,dp[1000000],cs=1,x;
char st[20][100],sy[100];

long long rec(long long vs)
{
    if(dp[vs]>=0)
    return dp[vs];

    if(vs==(1<<n)-1)
    return dp[vs]=1;

    long long i;

    dp[vs]=0;

    for(i=0;i<n;i++)
    {
        if(((musk[vs]>>i) & 1) && ((vs>>i) & 1)==0)
        dp[vs]+=rec(vs | (1<<i));
    }
    return dp[vs];
}

int main()
{
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        scanf("%s",&sy);

        for(i=0;i<n;i++)
        scanf("%s",st[i]);

        x=0;
        for(i=0;i<n;i++)
        x=x| ((sy[i]-'0')<<i);

        for(a=1;a<(1<<n);a++)
        {
            dp[a]=-1;
            musk[a]=x;

            for(i=0;i<n;i++)
            {
                if((a>>i) & 1)
                for(j=0;j<n;j++)
                musk[a]=musk[a] | ((st[i][j]-'0')<<j);
            }
        }

        a=0;
        for(i=0;i<n;i++)
        if(sy[i]=='1')
        a+=rec(1<<i);

        printf("Case %lld: %lld\n",cs++,a);
    }
    return 0;
}
