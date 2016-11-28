#include<stdio.h>
long long x,y,i,j,sum,cs=1,p;
int main()
{
    while(~scanf("%lld%lld",&x,&y))
    {
        sum=0LL;
        for(i=x;i*i*i<=y*20LL;i++)
        for(j=x;j*j*j<=y*20LL;j++)
        {
            p=(i*i*i+j*j*j);
            if(p%10==3 && p/10<=y)
            sum++;
//            printf("%lld %lld %lld %lld \n",i,i*i*i,j,j*j*j);
        }
        printf("Case %lld: %lld\n",cs++,sum);
    }
    return 0;
}
