#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char st[1000][250],sy[250],ss[250],sr[1000][250],c;
long t,lst,i,l1,l2,flag;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        lst=0;
        while(~scanf("%s%c",st[lst],&c))
        {
            strcpy(sr[lst],st[lst]);
            sort(sr[lst],sr[lst]+strlen(sr[lst]));
 //           printf("%s -",sr[lst]);
            lst++;
            if(c=='\n')
            break;
        }

        while(~scanf("%s%c",sy,&c))
        {
            l2=strlen(sy);
            strcpy(ss,sy);
            sort(ss,ss+l2);
            flag=1;
            for(i=0;i<lst;i++)
            {
                l1=strlen(st[i]);
                if(l1==l2 && st[i][0]==sy[0] && st[i][l1-1]==sy[l1-1] && strcmp(sr[i],ss)==0)
                {
                    strcpy(sy,st[i]);
                    flag=0;
                    break;
                }
            }
//            if(flag)
//            strcpy(st[lst++],sy);

            printf("%s",sy);

            if(c=='\n')
            {
                printf("\n");
                break;
            }
            else
            printf(" ");
        }

    }
    return 0;
}
