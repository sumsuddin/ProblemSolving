#include<stdio.h>
long w,y,x,z,sum,t;
double a,b,c,d;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        a*=100;b*=100,c*=100,d*=100;
        w=(long)a;
        x=(long)b;
        y=(long)c;
        z=(long)d;

        if(((w<=5600 && x<=4500 && y<=2500) || w+x+y<=12500) && z<=700)
        printf("1\n"),sum++;
        else
        printf("0\n");
    }
    printf("%ld\n",sum);
    return 0;
}
