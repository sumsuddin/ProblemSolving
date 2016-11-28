#include<stdio.h>
long i,j,d,ar[10050],ind[10050],flag,n;
int main()
{
    while(~scanf("%ld",&n) && n)
    {
        scanf(":");
        for(i=0;i<n;i++)
        scanf("%ld",&ar[i]),ind[ar[i]]=i;


        flag=1;
        for(i=0;i<n && flag;i++)
        for(j=i+1;j<n && flag;j++)
        {
            d=(ar[j]<<1)-ar[i];
            if(d>=0 && d<n && ind[d]>j)
            flag=0;
        }
        if(flag)
        printf("yes\n");
        else
        printf("no\n");
    }
    return 0;
}
