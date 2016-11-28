#include<stdio.h>
long i,j,n,tree[100050][10],h;
long long ans,M=1000000007;
char a[100005];

int main()
{
    while(~scanf("%ld",&n))
    {
        scanf("%s",&a);

        for(i=0;i<10;i++)
        tree[n+1][i]=0;

        for(i=n;i>0;i--)
        {
            for(j=0;j<10;j++)
            tree[i][j]=tree[i+1][j];

            tree[i][a[i-1]-'0']=i;
        }

        ans=0;
        for(i=1;i<=n;i++)
        {
            h=n;
            for(j=0;j<=9 && h>=i;j++)
            {
                if(tree[i][j]<=h && tree[i][j]>0)
                {
                    ans=(ans+((h-tree[i][j]+1)*j)%M)%M;
                    if(ans<0)
                    ans+=M;
                    h=tree[i][j]-1;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
