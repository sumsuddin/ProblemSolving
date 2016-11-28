#include<stdio.h>
#include<math.h>
#define inf 1000000000000000770LL
long long t,x,y,i,mx,sq;
int main()
{
    scanf("%lld",&t);

    while(t--)
    {
        mx=inf;
        scanf("%lld%lld",&x,&y);

        y-=2;

        if(y>=0)
        {
            x-=y;

            if(x==0)
            {
                printf("%lld\n",y+1);
                continue;
            }
            else if(x>0)
            {
                sq=sqrt(x);
                for(i=1;i<=sq;i++)
                {
                    if(x%i==0)
                    {
                        if(i>y && mx>i)
                        mx=i;

                        if((x/i)>y && mx>(x/i))
                        mx=x/i;
                    }
                }
            }
        }
        if(mx==inf)
        printf("Impossible\n");
        else
        printf("%lld\n",mx);
    }
    return 0;
}
