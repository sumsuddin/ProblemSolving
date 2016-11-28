#include<stdio.h>
long t,n,cs=1,d;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);
        printf("Case %ld: ",cs++);

        if(n%2)
        printf("Impossible\n");
        else
        {
            d=1;
            while(n%2==0)
            n/=2,d*=2;
            printf("%ld %ld\n",n,d);
        }
    }
    return 0;
}
