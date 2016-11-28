#include<stdio.h>
#include<string.h>
char A[110],B[110],C[110];

long t,cs,dp[110][110][110][2][2],vst[110][110][110][2][2];

long rec(long a,long b,long c,long xx,long yy)
{
    if(c==0 && a==0 && b==0)
    return 1;


    if(c<0 || a<0 || b<0)
    return 0;

    if(vst[a][b][c][xx][yy]==cs)
    return dp[a][b][c][xx][yy];

    vst[a][b][c][xx][yy]=cs;
    long x,y;

    dp[a][b][c][xx][yy]=0;

    if(xx==0 && a && c && A[a-1]==C[c-1])
    {
        x=1;
        dp[a][b][c][xx][yy]+=rec(a-1,b,c-1,0,0);
    }
    else
    x=0;

    if(yy==0 && b && c && B[b-1]==C[c-1])
    {
        y=1;
        dp[a][b][c][xx][yy]+=rec(a,b-1,c-1,0,0);
    }
    else
    y=0;

    dp[a][b][c][xx][yy]+=rec(a-1,b,c,x,y)+rec(a,b-1,c,x,y)-rec(a-1,b-1,c,x,y);

    return dp[a][b][c][xx][yy];
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        cs++;
        scanf("%s%s%s",A,B,C);

        printf("Case %ld: %ld\n",cs,rec(strlen(A),strlen(B),strlen(C),0,0));
    }
    return 0;
}
/*

32
a ab a

ab ab ab

abc abc abc
*/
