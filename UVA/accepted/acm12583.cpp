#include<stdio.h>
long cs=1,t,n,k,i,sum,j;
char st[10050];
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        sum=0;
        scanf("%ld%ld%s",&n,&k,&st);

        for(i=0;st[i];i++)
        for(j=i-1;j>=0 && j>=i-k;j--)
        if(st[i]==st[j])
        {
            sum++;
            break;
        }
        printf("Case %ld: %ld\n",cs++,sum);
    }
    return 0;
}
