#include<stdio.h>
#include<string.h>
long num[500],i,j,d,n,m;
char s[50],st[500][50];
int main()
{
    gets(s);
    sscanf(s,"%ld",&n);
    for(i=1;i<=n;i++)
    {
                     gets(s);
                     sscanf(s,"%ld",&m);
                     printf("Case %ld: ",i);
                     for(j=0;j<m;j++)
                     {   gets(s);
                         sscanf(s,"%s %ld",st[j],&num[j]);
                     }
                     gets(s);
                     sscanf(s,"%ld",&d);
                     gets(s);
                     for(j=0;j<m;j++)
                     {
                                     if(strcmp(st[j],s)==0)
                                     {
                                                            if(d>=num[j])
                                                            printf("Yesss\n");
                                                            else
                                                            if(d+5>=num[j])
                                                            printf("Late\n");
                                                            else
                                                            printf("Do your own homework!\n");
                                                            break;
                                     }
                     }
                     if(j==m)
                     printf("Do your own homework!\n");
    }
    return 0;
}
