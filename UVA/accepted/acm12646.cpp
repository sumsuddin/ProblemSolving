#include<stdio.h>
long a[10],i,d,ans;
int main()
{
    while(~scanf("%ld%ld%ld",&a[0],&a[1],&a[2]))
    {
        d=a[0]+a[1]+a[2];

        if(d==2)
        {
            for(i=0;i<3;i++)
            if(a[i]==0)
            ans=i;
        }
        else if(d==1)
        {
            for(i=0;i<3;i++)
            if(a[i])
            ans=i;
        }
        else
        ans=-1;

        if(ans==-1)
        printf("*\n");
        else
        printf("%s\n",ans==0?"A":(ans==1?"B":"C"));
    }
    return 0;
}
