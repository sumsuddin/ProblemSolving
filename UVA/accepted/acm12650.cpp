#include<stdio.h>

long n,m,i,flag,ind[10050],a;

int main()
{
    while(~scanf("%ld%ld",&n,&m))
    {
        for(i=1;i<=n;i++)
        ind[i]=1;

        if(m==n)
        flag=0;
        else
        flag=1;

        while(m--)
        scanf("%ld",&a),ind[a]=0;

        for(i=1;i<=n;i++)
        if(ind[i])
        printf("%ld ",i);

        if(flag)
        printf("\n");
        else
        printf("*\n");
    }
    return 0;
}
