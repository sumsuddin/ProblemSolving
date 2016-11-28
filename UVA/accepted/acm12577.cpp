#include<stdio.h>
#include<string.h>
char st[100];
long cs=1;
int main()
{
    while(~scanf("%s",st))
    {
        if(strcmp(st,"*")==0)
        break;

        if(strcmp(st,"Hajj"))
        printf("Case %ld: Hajj-e-Asghar\n",cs++);
        else
        printf("Case %ld: Hajj-e-Akbar\n",cs++);
    }
    return 0;
}
