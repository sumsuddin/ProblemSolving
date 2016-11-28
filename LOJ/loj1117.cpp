#include<stdio.h>
long long g,flag,d,m,i,lst,n,ans,t,a[20],j,mm,cs=1;

long long gcd(long long a,long long b)
{
    long long c=a%b;

    while(c)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

long long rec()
{
    lst=1<<n;

    ans=0;

    for(i=1;i<lst;i++)
    {
        d=0;
        g=1;
        flag=1;

        for(j=0;j<n;j++)
        if((i>>j) & 1)
        {
            d++;
            mm=g*a[j];
            g=gcd(g,a[j]);
            g=mm/g;

            if(g>m)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        continue;

        if(d%2)
        ans+=m/g;
        else
        ans-=m/g;
    }
    return ans;
}

int main()
{
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld%lld",&m,&n);

        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

        printf("Case %lld: %lld\n",cs++,m-rec());
    }
    return 0;
}
