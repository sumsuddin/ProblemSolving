#include<stdio.h>
long i,j,ind[300],ar[100050],t,n,q;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&n,&q);

        for(i=0;i<n;i++)
        scanf("%ld",&ar[i]);
        for(i=0;i<230;i++)
        ind[i]=0;

        for(i=0;i<230;i++)
        for(j=0;j<n;j++)
        if(ind[i]<(i&ar[j]))
        ind[i]=i&ar[j];


        while(q--)
        {
            scanf("%ld",&i);
            printf("%ld\n",ind[i]);
        }
    }
    return 0;
}
