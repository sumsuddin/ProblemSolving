#include<stdio.h>
long i,j,l,t,n,ii,mx,ind[100050],a,cs=1,tt;
bool bu[100050];
int main()
{
    scanf("%ld",&tt);

    while(tt--)
    {
        scanf("%ld%ld",&n,&t);

        l=t;

 //       l=t<10000?t:10000;


        for(i=0;i<=l;i++)
        ind[i]=0,bu[i]=0;
        bu[0]=1;

        for(i=0;i<n;i++)
        {
            scanf("%ld",&a);

            for(j=l-1;j>=0;j--)
            if(j+a<l && bu[j] && ind[j+a]<ind[j]+1)
            ind[j+a]=ind[j]+1,bu[j+a]=1;
        }
        ii=0;
        mx=0;
        for(i=0;i<l;i++)
        {
            if(bu[i])
            {
                if(mx<=ind[i])
                {
                    ii=i;
                    mx=ind[i];
                }
            }
        }
        printf("Case %ld: %ld %ld\n",cs++,mx+1,ii+678);
    }

    return 0;
}
