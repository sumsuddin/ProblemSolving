#include<stdio.h>
#include<vector>
using namespace std;

vector<long>vc[1050],wt[1050];

long cs=1,t,n,i,a,b,w;

bool vst[1050];

long rec(long n)
{
    vst[n]=0;

    int i;
    long ans=0;
    for(i=0;i<vc[n].size();i++)
    {
        if(vst[vc[n][i]])
        {
            long d=rec(vc[n][i]);
            if(wt[n][i]==1)
            ans^=1+d;
            else if(wt[n][i]%2)
            {
                if(d==0)
                ans^=1;
            }
            else
            ans^=d;
        }
    }
    return ans;
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);

        for(i=0;i<n;i++)
        vst[i]=1,vc[i].clear(),wt[i].clear();
        n--;

        while(n--)
        {
            scanf("%ld%ld%ld",&a,&b,&w);
            vc[a].push_back(b);
            vc[b].push_back(a);
            wt[a].push_back(w);
            wt[b].push_back(w);
        }

        i=rec(0);

        if(i)
        printf("Case %ld: Emily\n",cs++);
        else
        printf("Case %ld: Jolly\n",cs++);
    }
    return 0;
}
