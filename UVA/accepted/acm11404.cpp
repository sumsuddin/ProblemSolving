#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long dp[1050][1050],vst[1050][1050],prs,sst[1050][1050],go[1050][1050];
char st[1050],way[1050][1050];
void prnt(long a,long b);
long rec(long a,long b)
{
    if(a>b)
    return 0;

    if(vst[a][b]==prs)
    return dp[a][b];

    vst[a][b]=prs;

    if(a==b)
    return dp[a][b]=1;

    if(st[a]==st[b])
    return dp[a][b]=2+rec(a+1,b-1);

    return dp[a][b]=max(rec(a+1,b),rec(a,b-1));
}

long make(long a,long b)
{
    if(a>b)
    return 'z'+1;

    if(a==0 && b==5)
    a=a;

    if(sst[a][b]==prs)
    return go[a][b];


    sst[a][b]=prs;
    if(a==b)
    {
        way[a][b]='p';
        return go[a][b]=st[a];
    }

    if(st[a]==st[b])
    {
        make(a+1,b-1);
        way[a][b]='b';
        return go[a][b]=st[a];
    }

    if(rec(a+1,b)>rec(a,b-1))
    {
        way[a][b]='r';

        return go[a][b]=make(a+1,b);
    }
    else if(rec(a,b-1)>rec(a+1,b))
    {
        way[a][b]='l';
        return go[a][b]=make(a,b-1);
    }
    else
    {
        if(make(a+1,b)<make(a,b-1))
        {
            way[a][b]='r';
            return go[a][b]=make(a+1,b);
        }
        else if(make(a+1,b)>make(a,b-1))
        {
            way[a][b]='l';
            return go[a][b]=make(a,b-1);
        }
        else
        {
            long x=a,y=b,cc=make(a+1,b);
            while(1)
            {
                if(st[x]!=cc)
                {
                    way[x][y]='r';
                    sst[x][y]=prs;
                    go[x][y]=cc;
                    x++;
                }
                else if(st[y]!=cc)
                {
                    way[x][y]='l';
                    sst[x][y]=prs;
                    go[x][y]=cc;
                    y--;
                }
                else
                break;
            }
            sst[x][y]=prs;
            way[x][y]='b';
            return go[x][y]=make(x,y);
        }
    }
}

void prnt(long a,long b)
{
    if(a>b)
    return;
    if(a==b)
    printf("%c",st[a]);
    else if(st[a]==st[b])
    {
        printf("%c",st[a]);
        prnt(a+1,b-1);
        printf("%c",st[a]);
    }
    else if(way[a][b]=='l')
    prnt(a,b-1);
    else
    prnt(a+1,b);
}

int main()
{
    long i;
    prs=1;
    while(~scanf("%s",&st))
    {
        prs++;
        i=rec(0,strlen(st)-1);

        make(0,strlen(st)-1);

        prnt(0,strlen(st)-1);
        printf("\n");
    }

    return 0;
}
