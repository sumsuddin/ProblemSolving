#include<stdio.h>
#include<vector>
using namespace std;
vector<int>vc[100050],wt[100050];
struct ss
{
    int par[20],mx[20],mn[20],lvl;
}
info[100050];
int vst[100050],inf=100000000,mn,mx,t,n,i,a,b,w,cs=1;

int minv(int a,int b)
{
    return a<b?a:b;
}
int maxv(int a,int b)
{
    return a>b?a:b;
}

void rec(int n,int par,int mn,int mx,int lvl)
{
    vst[n]=0;

    info[n].par[0]=par;
    info[n].mx[0]=mx;
    info[n].mn[0]=mn;
    info[n].lvl=lvl;

    int i;
    for(i=1;i<20;i++)
    info[n].par[i]=-1,info[n].mx[i]=-1,info[n].mn[i]=inf;

    for(i=1;i<20;i++)
    {
        if(info[n].par[i-1]==-1)
        break;
        info[n].par[i]=info[info[n].par[i-1]].par[i-1];
        info[n].mn[i]=minv(info[info[n].par[i-1]].mn[i-1],info[n].mn[i-1]);
        info[n].mx[i]=maxv(info[info[n].par[i-1]].mx[i-1],info[n].mx[i-1]);
    }

    for(i=0;i<vc[n].size();i++)
    {
        if(vst[vc[n][i]])
        rec(vc[n][i],n,wt[n][i],wt[n][i],lvl+1);
    }
}

int find_par(int n,int p)
{
    if(p==0)
    return n;

    int i,x=1;

    for(i=0;i<20;i++)
    {
        if(p<2*x)
        break;
        x<<=1;
    }
    mn=minv(mn,info[n].mn[i]);
    mx=maxv(mx,info[n].mx[i]);

    find_par(info[n].par[i],p-x);
}

void find_lca(int a,int b)
{
    int i;
    if(info[a].lvl>info[b].lvl)
    {
        i=a;
        a=b;
        b=i;
    }

    b=find_par(b,info[b].lvl-info[a].lvl);

    if(a==b)
    return;

    for(i=19;i>=0;i--)
    {
        if(info[a].par[i]!=info[b].par[i])
        break;
    }
    if(i==-1)
    {
        mn=minv(mn,info[a].mn[0]);
        mn=minv(mn,info[b].mn[0]);

        mx=maxv(mx,info[a].mx[0]);
        mx=maxv(mx,info[b].mx[0]);
        return;
    }
    mn=minv(mn,info[a].mn[i]);
    mn=minv(mn,info[b].mn[i]);

    mx=maxv(mx,info[a].mx[i]);
    mx=maxv(mx,info[b].mx[i]);

    find_lca(info[a].par[i],info[b].par[i]);
}

int main()
{
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=1;i<=n;i++)
        vc[i].clear(),wt[i].clear(),vst[i]=1;

        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&w);

            vc[a].push_back(b);
            vc[b].push_back(a);
            wt[a].push_back(w);
            wt[b].push_back(w);
        }

        for(i=1;i<=n;i++)
        if(vst[i])
        rec(i,-1,inf,-1,1);

        printf("Case %d:\n",cs++);

        scanf("%d",&w);

        while(w--)
        {
            scanf("%d%d",&a,&b);
            mx=-1,mn=inf;

            find_lca(a,b);

            printf("%d %d\n",mn,mx);
        }
    }
    return 0;
}
