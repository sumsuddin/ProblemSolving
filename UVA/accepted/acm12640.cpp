#include<stdio.h>
long n,sum,mx;
char c;
int main()
{
    while(~scanf("%ld%c",&n,&c))
    {
        sum=n;
        mx=0;
        if(sum>mx)
        mx=sum;

        if(sum<0)
        sum=0;

        while(c!='\n')
        {
            scanf("%ld%c",&n,&c);
            sum+=n;

            if(sum>mx)
            mx=sum;

            if(sum<0)
            sum=0;
        }

        printf("%ld\n",mx);
    }
    return 0;
}
