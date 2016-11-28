#include<stdio.h>
#include<string.h>
long dp[65][65][65][65],t,cs=1,vis[65][65][65][65],now;
char st[100],sy[100];

long rec(long a,long b,long c,long d)
{
    if(a>b || c>d)
    return 0;

    if(vis[a][b][c][d]==now)
    return dp[a][b][c][d];

    vis[a][b][c][d]=now;
    if((a==b || c==d) && st[a]==sy[c])
    return dp[a][b][c][d]=1;

    if(a<b && c<d && st[a]==st[b] && sy[c]==sy[d] && st[a]==sy[c])
    return dp[a][b][c][d]=2+rec(a+1,b-1,c+1,d-1);

    long x,y;

    dp[a][b][c][d]=0;
    x=rec(a+1,b,c,d);
    y=rec(a,b-1,c,d);

    if(y<x)
    y=x;
    x=rec(a,b,c+1,d);
    if(y<x)
    y=x;

    x=rec(a,b,c,d-1);
    if(y<x)
    y=x;

    return dp[a][b][c][d]=y;
}

int main()
{
    scanf("%ld",&t);
    now=1;

    while(t--)
    {
        scanf("%s%s",&st,&sy);
        now++;

        printf("Case %ld: %ld\n",cs++,rec(0,strlen(st)-1,0,strlen(sy)-1));
    }
    return 0;
}
