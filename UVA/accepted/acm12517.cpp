#include<stdio.h>
long long n,m,ans,d,lst,fn[15],a,i;

long long rec(long long n)
{
    d=1;
    lst=0;

    while(d*10<=n)
    {
        d*=10;
        lst++;
    }
    ans=0;
 //   ans=fn[lst];

    while(n)
    {
        a=n/d;
        n%=d;

        for(i=0;i<a;i++)
        ans+=fn[lst],ans+=i*d;

        d/=10;
        ans+=a*(n+1);
        lst--;
    }
    return ans;
}

int main()
{
    fn[0]=0;
    d=1;
    for(i=1;i<10;i++)
    fn[i]=d*45+10*fn[i-1],d*=10;


    while(~scanf("%lld%lld",&n,&m) && (n|| m))
    {
        printf("%lld\n",rec(m)-rec(n-1));
    }
    return 0;
}
