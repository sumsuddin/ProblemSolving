#include<stdio.h>
#include<string.h>
long n,a,b,i,cs=1;
char st[100];
int main()
{
    scanf("%ld",&n);
    while(n--)
    {
        a=b=0;
        scanf("%s",st);
        for(i=0;st[i];i++)
        if(st[i]<='9' && st[i]>='0')
        a=a*10+(st[i]-'0');
        else
        break;

        for(;i<strlen(st);i++)
        if(st[i]>='0' && st[i]<='9')
        b=b*10+(st[i]-'0');

        if(b>0)
        a=a*50+b*5;
        else
        a=a*50;

        if(a%100==0)
        printf("Case %ld: %ld\n",cs++,a/100);
        else if(a%10==0)
        printf("Case %ld: %.1lf\n",cs++,(double)a/100.0);
        else
        printf("Case %ld: %.2lf\n",cs++,(double)a/100.0);
    }
}
