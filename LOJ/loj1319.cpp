#include<stdio.h>

long cs=1,mm[100],r[100],m,ans,i,s[100],t,n,pr[100],x,y;

void ext(long a, long b){
    long x1;
    if(b>a)
    {
        x1=a; //if b>a so I used this if condition
        a=b; // result is ok but x and y swaped
        b=x1;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    ext(b,a%b);
    x1 = x-(a/b) * y;
    x = y;
    y = x1;
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);

        m=1;
        for(i=0;i<n;i++)
        scanf("%ld%ld",&pr[i],&r[i]),m*=pr[i];

        for(i=0;i<n;i++)
        mm[i]=(m/pr[i]);

        for(i=0;i<n;i++)
        {
            ext(mm[i]%pr[i],pr[i]);
            s[i]=(pr[i]+y)%pr[i];
        }

        ans=0;

        for(i=0;i<n;i++)
        ans=ans+(mm[i]*s[i]*r[i])%m;
        printf("Case %ld: %ld\n",cs++,ans%m);
    }
    return 0;
}
