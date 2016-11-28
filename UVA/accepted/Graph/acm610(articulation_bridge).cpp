#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<long>vc[1050],chld[1050],bkeg[1050];
bool vst[1050],vis[1050][1050];
long i,j,par[1050],L[1050],dfn[1050],a,b,time,n,ans,m,lst,t,cs=1;


void dfs(long p)
{
    long i,d,mn;

    for(i=0; i<vc[p].size(); i++)
    {
        d=vc[p][i];
        if(vst[d])
        {
            par[d]=p;

            vst[d]=0;
            dfn[d]=time++;
            chld[p].push_back(d);
            dfs(d);
        }
        else if(d!=par[p])
            bkeg[d].push_back(p),bkeg[p].push_back(d);
    }
    mn=dfn[p];

    for(i=0; i<chld[p].size(); i++)
    {
        d=chld[p][i];
        if(L[d]<mn)
            mn=L[d];

        if(L[d]>dfn[p])
        {
            printf("%ld %ld\n",p,d);
            printf("%ld %ld\n",d,p);
        }
        else
            printf("%ld %ld\n",p,d);
    }
    for(i=0; i<bkeg[p].size(); i++)
    {
        d=bkeg[p][i];
        if(dfn[d]<mn)
            mn=dfn[d];
        if(vis[p][d]==0)
        {
            printf("%ld %ld\n",p,d);
            vis[p][d]=1;
            vis[d][p]=1;
        }
    }
    L[p]=mn;
}

int main()
{
    while(scanf("%ld%ld",&n,&m) && ( m||n))
    {
        ;
        for(i=1; i<=n; i++)
        {
            vc[i].clear(),bkeg[i].clear(),chld[i].clear();
            vst[i]=1;
            for(j=1; j<=n; j++)
                vis[i][j]=0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%ld%ld",&a,&b);
            vc[a].push_back(b);
            vc[b].push_back(a);
        }


        time=1;
        printf("%ld\n\n",cs++);
        for(i=1; i<=n; i++)
        {
            if(vst[i])
            {
                dfn[i]=time++;
                vst[i]=0;
                par[i]=-1;
                dfs(i);
            }
        }
        printf("#\n");
    }
    return 0;
}
