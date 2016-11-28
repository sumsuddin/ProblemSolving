#include<stdio.h>
long i,j;
char st[10000];
int main()
{
    while(~scanf("%*ld"))
    {
        for(i=0;i<5;i++)
        {
            scanf("%s",&st);
            if(i==3)
            {
                for(j=0;st[j];j++)
                if(j%4==1 && st[j]=='*')
                printf("1");
                else if(j%4==0 && st[j]=='*')
                printf("2");
                else if(j%4==2 && st[j]=='*')
                printf("3");
            }
        }
        printf("\n");
    }
    return 0;
}
