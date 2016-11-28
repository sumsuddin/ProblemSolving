#include<stdio.h>
double ans;
long n,t,i,cs=1;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);

        ans=0.0;

        for(i=1;i<=n;i++)
        {
            ans=(double)n+(double)i*ans;
            ans/=(double)i;
        }
        printf("Case %ld: %.15lf\n",cs++,ans);
    }
    return 0;
}
