#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<long>vc[50050],vt[50050];
struct ss
{
    long ind,fn;
}
sr[100050];
bool vst[100050];
long cs=1,indeg[100050],outdeg[100050],par[100050],tim,scc,t,n,m,u,v,i;

bool cmp(ss a,ss b)
{
    return a.fn>b.fn;
}

void dfn(long n)
{
    vst[n]=0;

    long i;
    for(i=0;i<vt[n].size();i++)
    if(vst[vt[n][i]])
    tim++,dfn(vt[n][i]);
    sr[n].fn=++tim;
}

void acm(long n)
{
    vst[n]=0;

    long i;

    for(i=0;i<vc[n].size();i++)
    if(vst[vc[n][i]])
    acm(vc[n][i]);

    par[n]=scc;
}

void call(long n)
{
    vst[n]=0;
    long i;
    for(i=0;i<vc[n].size();i++)
    {
        if(par[vc[n][i]]!=par[n])
        outdeg[par[n]]++;

        if(vst[vc[n][i]])
        {
            if(par[vc[n][i]]!=par[n])
            indeg[par[vc[n][i]]]++;
            call(vc[n][i]);
        }
    }
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&n,&m);

        for(i=1;i<=n;i++)
        vst[i]=1,sr[i].ind=i,sr[i].fn=0;

        while(m--)
        {
            scanf("%ld%ld",&u,&v);

            vc[u].push_back(v);
            vt[v].push_back(u);
        }

        tim=0;
        for(i=1;i<=n;i++)
        if(vst[i])
        tim++,dfn(i);

        sort(sr+1,sr+n+1,cmp);

        for(i=1;i<=n;i++)
        vst[i]=1;

        scc=0;
        for(i=1;i<=n;i++)
        if(vst[sr[i].ind])
        {
            ++scc;
            indeg[scc]=outdeg[scc]=0;
            acm(sr[i].ind);
        }

        for(i=1;i<=n;i++)
        vst[i]=1;

        for(i=1;i<=n;i++)
        if(vst[i])
        call(i);
        indeg[0]=outdeg[0]=0;
        for(i=1;i<=scc;i++)
        {
            if(indeg[i]==0)
            indeg[0]++;
            if(outdeg[i]==0)
            outdeg[0]++;
        }
        printf("Case %ld: %ld\n",cs++,indeg[0]>outdeg[0]?indeg[0]:outdeg[0]);
    }

    return 0;
}
