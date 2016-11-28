#include<stdio.h>
long t,n,mx,a,cs=1;
long max(long a,long b)
{
    return a>b?a:b;
}
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);
        mx=0;

        while(n--)
        scanf("%ld",&a),mx=max(a,mx);
        printf("Case %ld: %ld\n",cs++,mx);
    }
    return 0;
}
