#include<stdio.h>
long long dp[40000][20][4],n,mat[20][20],fact[20],t,i,j,cs=1;
void rec(long long vs,long long now)
{
    if(dp[vs][now][0]>=0)
    return ;

    long long i;
    dp[vs][now][0]=dp[vs][now][1]=dp[vs][now][2]=0;

    if(now==0)
    {
        for(i=0;i<n;i++)
        if(((vs>>i) & 1)==0 && mat[i][now])
        dp[vs][now][mat[i][now]]++;

        return ;
    }
    for(i=0;i<n;i++)
    {
        if(((vs>>i) & 1) ==0)
        {
            rec((vs | (1<<i)) , now-1);

            if(mat[i][now]==2)
            dp[vs][now][mat[i][now]]+=fact[now];
            else
            {
                if(mat[i][now]==1)
                dp[vs][now][1]+=dp[vs | (1<<i)][now-1][1];

                dp[vs][now][2]+=dp[vs | (1<<i)][now-1][2];
            }
        }
    }
}

int main()
{
    scanf("%lld",&t);

    fact[0]=1;
    for(i=1;i<16;i++)
    fact[i]=i*fact[i-1];


    while(t--)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%lld",&mat[i][j]);

        for(i=0;i<(1<<n);i++)
        for(j=0;j<n;j++)
        dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-1;

        rec(0,n-1);

        i=dp[0][n-1][0]+dp[0][n-1][1]+dp[0][n-1][2];

        printf("Case %lld: %lld\n",cs++,i);
    }
    return 0;
}
