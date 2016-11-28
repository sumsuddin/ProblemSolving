#include<stdio.h>
long t,r,w,lc,rc,cs=1;
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&r);

        r*=5;
        w=(r*6)/20;

        lc=(r*45)/100;
        rc=(r*55)/100;

        printf("Case %ld:\n%ld %ld\n%ld %ld\n%ld %ld\n%ld %ld\n",cs++,-lc,w,rc,w,rc,-w,-lc,-w);
    }
    return 0;
}
