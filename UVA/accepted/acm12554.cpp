#include<stdio.h>
#include<string.h>
int main()
{
    long tru;
    char st[150][150],sy[150][1000];
    long i,j,n,flag;

    strcpy(st[0],"Happy");
    strcpy(st[1],"birthday");
    strcpy(st[2],"to");
    strcpy(st[3],"you");
    strcpy(st[4],"Happy");
    strcpy(st[5],"birthday");
    strcpy(st[6],"to");
    strcpy(st[7],"you");
    strcpy(st[8],"Happy");
    strcpy(st[9],"birthday");
    strcpy(st[10],"to");
    strcpy(st[11],"Rujia");
    strcpy(st[12],"Happy");
    strcpy(st[13],"birthday");
    strcpy(st[14],"to");
    strcpy(st[15],"you");

    while(~scanf("%ld",&n))
    {
        flag=0;
        for(i=0;i<n;i++)
        scanf("%s",&sy[i]);
        tru=1;
        for(i=0,j=0;tru;)
        {
            printf("%s: %s\n",sy[j++],st[i++]);
            if(j==n)
            j=0,flag=1;
            if(i==16 && flag)
            tru=0;
            if(i==16)
            i=0;
        }
    }

    return 0;
}
