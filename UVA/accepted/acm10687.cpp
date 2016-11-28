#include<stdio.h>
#include<algorithm>
using namespace std;
struct ss
{
    long ind,x,y,dist;
}
mn[1050][1050];

long i,j,n,x[1050],y[1050];
bool vst[1050],flag;

bool cmp(ss p,ss q)
{
    if(p.dist==q.dist)
    {
        if(p.x==q.x)
        return p.y<q.y;
        else
        return p.x<q.x;
    }
    else
    return p.dist<q.dist;
}

void rec(long n)
{
    if(vst[n]==0)
    return;
    vst[n]=0;
    rec(mn[n][0].ind);
    rec(mn[n][1].ind);
}

int main()
{
    while(~scanf("%ld",&n) && n)
    {
        flag=1;

        for(i=0;i<n;i++)
        scanf("%ld%ld",&x[i],&y[i]),vst[i]=1;

        for(i=0;i<n;i++)
        {
            mn[i][i].ind=i,mn[i][i].x=x[i],mn[i][i].y=y[i],mn[i][i].dist=1000000000;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    mn[i][j].ind=j,mn[i][j].x=x[j],mn[i][j].y=y[j],mn[i][j].dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                }
            }
            sort(mn[i],mn[i]+n,cmp);
        }

        rec(0);

        for(i=0;i<n;i++)
        if(vst[i])
        flag=0;

        if(flag || n<4)
        printf("All stations are reachable.\n");
        else
        printf("There are stations that are unreachable.\n");
    }
    return 0;
}
