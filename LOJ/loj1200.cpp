#include<stdio.h>

long n,w,i,j,wt[10050],t,cs=1;
struct ss
{
    long p,c,w;
}
sr[150];

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&n,&w);

        for(i=0;i<n;i++)
        scanf("%ld%ld%ld",&sr[i].p,&sr[i].c,&sr[i].w),w-=sr[i].c*sr[i].w;

        if(w<0)
        printf("Case %ld: Impossible\n",cs++);
        else
        {
            for(i=0;i<=w;i++)
            wt[i]=0;

            for(i=0;i<n;i++)
            for(j=0;j<=w;j++)
            {
                if(j+sr[i].w<=w && wt[j+sr[i].w]<wt[j]+sr[i].p)
                wt[j+sr[i].w]=wt[j]+sr[i].p;
            }
            j=0;
            for(i=0;i<=w;i++)
            if(wt[i]>j)
            j=wt[i];
            printf("Case %ld: %ld\n",cs++,j);
        }
    }
    return 0;
}
