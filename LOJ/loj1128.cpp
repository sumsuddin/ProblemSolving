#include<stdio.h>
long t,i,n,m,j,k,v,par[100050][30],value[100050][30],cs=1,tru,vv[100050];
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&n,&m);

        //initialize..
        for(i=0;i<=n;i++)
        for(j=0;(1<<j)<=n;j++)
        par[i][j]=-1,value[i][j]=0;

        vv[0]=1;

        for(i=1;i<n;i++)
        scanf("%ld%ld",&par[i][0],&vv[i]);

        for(i=1;i<=n;i++)
        if(par[i][0]!=-1)
        value[i][0]=vv[par[i][0]];

        //updating the 2^jth  parent....by the concept : who is my grandfather? ans: my father's father.(something like that). This is called sparce table.
        for(i=0;i<=n;i++)
        for(j=1;(1<<j)<=n;j++)
        if(par[i][j-1]!=-1)
        {
            par[i][j]=par[par[i][j-1]][j-1];
            value[i][j]=vv[par[i][j]];
        }

        printf("Case %ld:\n",cs++);
        while(m--)
        {
            scanf("%ld%ld",&k,&v);
            tru=1;
            while(tru)
            {
                tru=0;
                for(i=0;(1<<i)<=n;i++)
                {
                    if(par[k][i]==-1 || value[k][i]<v || k==0)
                    break;
                    tru=1;
                }
                if(tru)
                k=par[k][i-1];
            }
            printf("%ld\n",k);
        }
    }
    return 0;
}
