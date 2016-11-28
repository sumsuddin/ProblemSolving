#include<cstdio>
#include<cstring>
#define Z 102
#define max(x,y)(x>y)?x:y
long a[Z],dp[Z][Z][Z],n;

long rec(long pos,long lf,long rt,long mn,long mx)
{
    if(pos>=n)
    return lf+rt;

    long &t=dp[pos][lf][rt],x,y,z;
    if(t!=-1)
    return t;
    t=0;
    if(a[pos]>mn && a[pos]<mx)
    {
        x=rec(pos+1,lf+1,rt,a[pos],mx);
        t=max(x,t);
        y=rec(pos+1,lf,rt+1,mn,a[pos]);
        t=max(y,t);
        z=rec(pos+1,lf,rt,mn,mx);
        t=max(z,t);
        return t;
    }
    return t=lf+rt;
}

int main()
{
    long t,i,j,cs=1;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
        memset(dp,-1,sizeof(dp));
        j=rec(0,0,0,0,(1<<28));
        printf("Case %ld: %ld\n",cs++,j);
    }
    return 0;
}
