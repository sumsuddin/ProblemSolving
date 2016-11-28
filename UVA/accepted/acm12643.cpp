#include<stdio.h>
long n,i,j,k,d;
int main()
{
    while(~scanf("%ld%ld%ld",&n,&i,&j))
    {
        d=1;
        for(k=0;k<n;k++)
        d<<=1;
        while(n)
        {
            if(((i-1)/d)!=((j-1)/d))
            break;
            d>>=1;
            n--;
        }

        printf("%ld\n",n+1);
    }
    return 0;
}
