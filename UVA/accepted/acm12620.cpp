#include<stdio.h>
long long fn[350],com[350],i,j,flag,t;
int main()
{
    fn[0]=0LL;
    com[0]=0LL;
    fn[1]=1LL;
    com[1]=1LL;

    for(i=2;i<300;i++)
    {
        fn[i]=fn[i-1]+fn[i-2];
        fn[i]%=100LL;
        com[i]=com[i-1]+fn[i];
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&i,&j);
        i--;
        flag=(j/300LL)*com[299]+com[j%300];
        flag-=(i/300LL)*com[299]+com[i%300];
        printf("%lld\n",flag);
    }
    return 0;
}
