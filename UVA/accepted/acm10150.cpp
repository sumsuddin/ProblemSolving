#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<queue>
using namespace std;

map<string,long>mp;
map<string,long>::iterator it;
vector<long>vc[30000];
queue<long>que;

bool flag,tru=1,xtra;
char st[30000][20],sy[100],sr[100];
long vst[30000],prs,dest,n,i,par[30000],j,k;

void bfs(long n)
{
    long i;
    que.push(n);
    vst[n]=prs;

    while(!que.empty())
    {
        n=que.front();
        que.pop();

        if(n==dest)
        {
            while(!que.empty())
            que.pop();
            xtra=1;
        }

        for(i=0;i<vc[n].size();i++)
        {
            if(vst[vc[n][i]]!=prs)
            {
                vst[vc[n][i]]=prs;
                par[vc[n][i]]=n;
                que.push(vc[n][i]);
            }
        }
    }
}

void prin(long n)
{
    if(par[n]==-1)
    {
        printf("%s\n",st[n]);
        return;
    }

    prin(par[n]);
    printf("%s\n",st[n]);
}

int main()
{
    n=0;
    while(gets(st[n]) && st[n][0])
    mp[st[n]]=n++;

    for(i=0;i<n;i++)
    {
        for(j=0;st[i][j];j++)
        {
            strcpy(sy,st[i]);
            for(k=0;k<26;k++)
            {
                sy[j]=k+'a';
                it=mp.find(sy);
                if(it!=mp.end() && strcmp(st[i],sy))
                vc[i].push_back(mp[sy]);
            }
        }
    }
    prs=1;
    while(~scanf("%s%s",&sy,&sr))
    {
        if(tru)
        tru=0;
        else
        printf("\n");

        flag=1;

        it=mp.find(sr);
        if(it==mp.end())
        flag=0;
        else
        dest=mp[sr];

        it=mp.find(sy);
        if(it==mp.end())
        flag=0;

        if(flag && strcmp(sr,sy)==0)
        {
            if(vc[mp[sr]].size())
            printf("%s\n%s\n%s\n",sr,st[vc[mp[sr]][0]],sr);
            else
            printf("No solution.\n");
            continue;
        }

        xtra=0;

        if(flag)
        {
            par[mp[sy]]=-1;
            bfs(mp[sy]);
        }

        if(flag==0 || xtra==0)
        printf("No solution.\n");
        else
        prin(dest);
        prs++;
    }

    return 0;
}
