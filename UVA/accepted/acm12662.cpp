#include<stdio.h>
#include<string.h>
char st[150][10];
long n,i,a,q,j;
int main()
{
    while(~scanf("%ld",&n))
    {
        for(i=0;i<n;i++)
        scanf("%s",&st[i]);

        scanf("%ld",&q);

        while(q--)
        {
            scanf("%ld",&a);
            a--;

            if(st[a][0]!='?')
            {
                printf("%s\n",st[a]);
                continue;
            }

            for(i=1;i<n;i++)
            {
                if(a-i>=0 && a+i <n && strcmp(st[a-i],"?") && strcmp(st[a+i],"?"))
                {
                    printf("middle of %s and %s\n",st[a-i],st[a+i]);
                    break;
                }
                else if(a-i >=0 && strcmp(st[a-i],"?"))
                {
                    j=i;
                    while(j--)
                    printf("right of ");
                    printf("%s\n",st[a-i]);
                    break;
                }
                else if(a+i<n && strcmp(st[a+i],"?"))
                {
                    j=i;
                    while(j--)
                    printf("left of ");
                    printf("%s\n",st[a+i]);
                    break;
                }
            }
        }
    }
    return 0;
}
