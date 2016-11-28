#include<stdio.h>

long flag,l,h,n,m,i,j,r;
bool bu[1000050];
int main()
{
    while(~scanf("%ld%ld",&n,&m) && (n||m))
    {
        for(i=0;i<=1000000;i++)
        bu[i]=0;
        flag=1;
        while(n--)
        {
            scanf("%ld%ld",&l,&h);

            for(i=l+1;i<1000001 && i<=h && flag;i++)
            {
                if(bu[i])
                flag=0;
                else
                bu[i]=1;
            }
        }
        while(m--)
        {
            scanf("%ld%ld%ld",&l,&h,&r);

            while(l<=1000000)
            {
                for(i=l+1;i<=1000000 && i<=h;i++)
                if(bu[i])
                flag=0;
                else
                bu[i]=1;

                l+=r;
                h+=r;
            }
        }
        if(flag)
        printf("NO CONFLICT\n");
        else
        printf("CONFLICT\n");
    }
    return 0;
}
