#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10100   

char st[MAX];

int main()
{
	char xx[MAX];

    int a,n,len,i,j;

	gets(xx);
    sscanf(xx, "%d ",&n);
    while(n--)
    {
        gets(st);
        len=strlen(st);

        a=(int)sqrt(len);

        if(a*a!=len)
            printf("INVALID\n");
        else
        {
            for(i=0;i<a;i++)
            {
                for(j=i;j<len;j+=a)
                    printf("%c",st[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
