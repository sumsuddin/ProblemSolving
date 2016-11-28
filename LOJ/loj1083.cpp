#include<cstdio>
#include<cstring>
#define Z 102
#define max(x,y)(x>y)?x:y
long a[Z],dp[Z][Z][Z],vis[Z][Z][Z],n,prs;

long rec(long pos,long l,long r)
{
    if(pos>=n)
    return 0;

    if(vis[pos][l][r]==prs)
    return dp[pos][l][r];

    vis[pos][l][r]=prs;

    dp[pos][l][r]=rec(pos+1,l,r);

    if((l==-1 || a[l]<=a[pos] ) && (r==-1 || a[r]>=a[pos]))
    {
        dp[pos][l][r]=max(dp[pos][l][r],rec(pos+1,pos,r)+1);
        dp[pos][l][r]=max(dp[pos][l][r],rec(pos+1,l,pos)+1);
    }

    return dp[pos][l][r];

}

int main()
{
    long t,i,j,cs=1;
    scanf("%ld",&t);
    prs=0;
    while(t--)
    {
        prs++;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        scanf("%ld",&a[i]);

        printf("Case %ld: %ld\n",prs,rec(0,-1,-1));
    }
    return 0;
}
