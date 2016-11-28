#include<stdio.h>

long a,b,c,d,ma,mb,i,t;
char st[1000];

int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%s",&st);

        a=0,b=1;

        c=1,d=0;

        for(i=0;st[i];i++)
        {
            ma=a+c;
            mb=b+d;

            if(st[i]=='R')
            {
                a=ma;
                b=mb;
            }
            else
            {
                c=ma;
                d=mb;
            }
        }
        ma=a+c;
        mb=b+d;

        printf("%ld/%ld\n",ma,mb);
    }
    return 0;
}
