#include<stdio.h>
long t,w,wt,ww,n,dis,sum;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&w,&n);
        ww=sum=0;
        while(n--)
        {
            scanf("%ld%ld",&dis,&wt);
            ww+=wt;
            if(ww==w)
            {
                sum+=2*dis;
                ww=0;
            }
            else if(ww>w)
            {
                ww=wt;
                sum+=2*dis;
            }
        }
        if(ww)
        sum+=2*dis;
        printf("%ld\n",sum);
    }
    return 0;
}
