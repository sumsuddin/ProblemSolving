#include<stdio.h>
long a,b,c,d,l,i,sum;
int main()
{
    while(scanf("%ld%ld%ld%ld%ld",&a,&b,&c,&d,&l) && (a || b || c || d || l))
    {
           sum=0;                                       
           for(i=0;i<=l;i++)
           {
                  if(((a*i*i+b*i+c)%d)==0)
                      sum++;
           }
           printf("%ld\n",sum);
    }
    return 0;
}                                       
