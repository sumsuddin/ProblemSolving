#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[1050];

long vst[10050][5],dp[10050][5],present,par[10050],vs[10050];

long rec(long n,long now)
{
    vs[n]=0;
    if(vst[n][now]==present)
    return dp[n][now];

    if(n==0)
    return 0;

    long a=0,i,p;
    vst[n][now]=present;
    for(i=0;i<vc[n].size();i++)
    {
        p=vc[n][i];

        if(p!=par[n])
        {
            par[p]=n;
            if(now==0)
            a+=rec(p,1);
            else
            a+=min(rec(p,1),rec(p,0));
        }
    }

    return dp[n][now]=a+now;
}

int main()
{
    long i,n,m,j,a;
    present=0;
    while(~scanf("%ld",&n) && n)
    {
        present++;
        for(i=0;i<=n;i++)
        vc[i].clear();

        for(i=1;i<=n;i++)
        {
            vs[i]=1;
            par[i]=i;
            scanf("%ld",&m);
            for(j=0;j<m;j++)
            scanf("%ld",&a),vc[i].push_back(a);
        }
        a=0;
        for(i=1;i<=n;i++)
        if(vs[i])
        {
            m=min(rec(i,1),rec(i,0));
            if(m==0)
            m=1;
            a+=m;
        }

        printf("%ld\n",a);
    }

    return 0;
}
