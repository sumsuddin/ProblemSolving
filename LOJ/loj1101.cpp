#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

long maxv(long a,long b)
{
    return a>b?a:b;
}

vector<long>vc[100050],wt[100050];
bool vst[100050];
long i,j,t,n,m,par[100050],rank[100050],p,q,cs=1,mx,lvl[100050],anst[100050][20],cost[100050][20];
struct ss
{
    long u,v,cst;

    bool operator < (ss x)
    const{
        return cst<x.cst;
    }
}
sr[100050];

long parent(long p)
{
    if(par[p]!=p)
    par[p]=parent(par[p]);

    return par[p];
}

void rec(long p,long pr,long mx,long lv)
{
    vst[p]=0;
    lvl[p]=lv;
    anst[p][0]=pr;
    cost[p][0]=mx;
    long i,sz=vc[p].size();


    for(i=1;i<20;i++)
    {
        if(anst[p][i-1]==-1)
        break;
        anst[p][i]=anst[anst[p][i-1]][i-1];
        cost[p][i]=maxv(cost[p][i-1],cost[anst[p][i-1]][i-1]);
    }

    for(i=0;i<sz;i++)
    if(vst[vc[p][i]])
    rec(vc[p][i],p,wt[p][i],lv+1);
}

long find_par(long n,long p)
{
    if(p==0)
    return n;

    long i,x=1;

    for(i=0;i<20;i++)
    {
        if(p<(x<<1))
        break;

        x<<=1;
    }
    mx=maxv(mx,cost[n][i]);
    return find_par(anst[n][i],p-x);
}

void find_lca(long a,long b)
{
    long i;
    if(lvl[a]>lvl[b])
    {
        i=a;
        a=b;
        b=i;
    }

    b=find_par(b,lvl[b]-lvl[a]);

    if(a==b)
    return;

    for(i=19;i>=0;i--)
    if(anst[a][i]!=anst[b][i])
    break;

    if(i==-1)
    {
        mx=maxv(mx,cost[a][0]);
        mx=maxv(mx,cost[b][0]);
        return;
    }
    mx=maxv(mx,cost[a][i]);
    mx=maxv(mx,cost[b][i]);

    find_lca(anst[a][i],anst[b][i]);
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&n,&m);

        for(i=0;i<=n;i++)
        {
            vst[i]=1;
            rank[i]=0;
            par[i]=i;
            vc[i].clear();
            wt[i].clear();
            for(j=0;j<20;j++)
            {
                anst[i][j]=-1;
                cost[i][j]=-1;
            }
        }

        for(i=0;i<m;i++)
        scanf("%ld%ld%ld",&sr[i].u,&sr[i].v,&sr[i].cst);

        sort(sr,sr+m);

        for(i=0;i<m;i++)
        {
            p=parent(sr[i].u);
            q=parent(sr[i].v);
            if(p!=q)
            {
                if(rank[p]>rank[q])
                rank[p]++,par[q]=p;
                else
                rank[q]++,par[p]=q;

                vc[sr[i].u].push_back(sr[i].v);
                vc[sr[i].v].push_back(sr[i].u);

                wt[sr[i].u].push_back(sr[i].cst);
                wt[sr[i].v].push_back(sr[i].cst);
            }
        }

        for(i=1;i<=n;i++)
        if(vst[i])
        rec(i,-1,-1,0);

        printf("Case %ld:\n",cs++);
        scanf("%ld",&m);
        while(m--)
        {
            scanf("%ld%ld",&p,&q);
            mx=-1;

            find_lca(p,q);

            printf("%ld\n",mx);
        }
    }
    return 0;
}
