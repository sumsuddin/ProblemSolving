#include<stdio.h>
long long a,b;
long long rec(long long n)
{
    if(n<=0)
    return 0;
    long long up,d,ans,fn;
    up=0;
    d=1;
    ans=fn=0;
    while(n>=up+d)
    {
        up+=d;
        ans=fn+d;
        fn+=ans;
        d<<=1;
    }
    return fn+(n-up)+rec(n-d);
}

int main()
{
    while(~scanf("%lld%lld",&a,&b))
    {
        printf("%lld\n",rec(b)-rec(a-1));
    }
    return 0;
}
