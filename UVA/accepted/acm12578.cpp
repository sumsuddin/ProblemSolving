#include<stdio.h>
#include<math.h>
#define pi acos(-1.0)
long t;
double n,y,r;
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%lf",&n);
        y=(n*6.0)/10.0;
        r=n/5.0;

        printf("%.2lf %.2lf\n",pi*r*r,n*y-pi*r*r);
    }
    return 0;
}
