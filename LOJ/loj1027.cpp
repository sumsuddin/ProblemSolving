#include<stdio.h>
long gcd(long x,long y)
{
     long c;
     while(1)
     {
            c=x%y;
     if(c==0)
     {
             return y;
     }
           x=y;
           y=c;
     }
}
int main()
{
    long n,i,l,a,sm,ne,y,x,t,cs=1;
    scanf("%ld",&t);
    while(t--)
    {
              scanf("%ld",&n);
              ne=0;sm=0;
              for(i=0;i<n;i++)
              {
              scanf("%ld",&a);
              if(a<0)
              {
                        ne++;a=-a;
              }
              sm+=a;


              }
              x=n-ne;
              if(x)
              {
               y=gcd(x,sm);

               printf("Case %ld: %ld/%ld\n",cs++,sm/y,x/y);
               }
               else
               printf("Case %ld: inf\n",cs++);
    }
    return 0;
}

