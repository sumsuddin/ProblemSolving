#include<stdio.h>
long i,k,n,t,cs=1;
double lb,hr,gld[110],x[110];
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);

        for(i=1;i<=n;i++)
        scanf("%lf",&gld[i]);
        x[n]=gld[n];

        for(k=n-1;k>0;k--)
        {
            lb=0;hr=6;
            for(i=1;i<7;i++)
            {
                            if(k+i>n)
                            hr--;
                            else
                            lb+=(gld[k]+x[k+i]);

            }
            x[k]=(lb/hr);
        }
        printf("Case %ld: %.6lf\n",cs++,x[1]);
    }
    return 0;
}
