#include<stdio.h>
#include<math.h>
long t,n,i,l,d;
double dubl[10000010];
int main()
{
 	dubl[0]=0;
    for(i=1;i<=10000000;i++)
        dubl[i]=dubl[i-1]+(log(i)/log(10)); 	
 	scanf("%ld",&t);
 	while(t--)
 	{
         scanf("%ld",&n);
         printf("%ld\n",(long)(floor)(dubl[n])+1);
    }
    return 0;
}
