#include<stdio.h>
long i,j,sum[500][500],mat[500][500],n,t,cs=1;
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%ld",&mat[i][j]);
                sum[i][j]=mat[i][j];
            }
        }
        for(i=n-1;i>0;i--)
        {
            for(j=1;j<=i;j++)
                scanf("%ld",&mat[2*n-i][j]),sum[2*n-i][j]=mat[2*n-i][j];
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<=i;j++)
                {
                    if(mat[i+1][j]+sum[i][j]>sum[i+1][j])
                        sum[i+1][j]=mat[i+1][j]+sum[i][j];
                    
                    if(mat[i+1][j+1]+sum[i][j]>sum[i+1][j+1])
                        sum[i+1][j+1]=mat[i+1][j+1]+sum[i][j];
                }
        }
        for(i=n;i>0;i--)
        {
            if(mat[2*n-i+1][1]+sum[2*n-i][1]>sum[2*n-i+1][1])
                sum[2*n-i+1][1]=mat[2*n-i+1][1]+sum[2*n-i][1];
                
            for(j=2;j<i;j++)
                {
                    if(mat[2*n-i+1][j-1]+sum[2*n-i][j]>sum[2*n-i+1][j-1])
                        sum[2*n-i+1][j-1]=mat[2*n-i+1][j-1]+sum[2*n-i][j];
                    
                    if(mat[2*n-i+1][j]+sum[2*n-i][j]>sum[2*n-i+1][j])
                        sum[2*n-i+1][j]=mat[2*n-i+1][j]+sum[2*n-i][j];
                }
            if(mat[2*n-i+1][j-1]+sum[2*n-i][j]>sum[2*n-i+1][j-1])
                sum[2*n-i+1][j-1]=mat[2*n-i+1][j-1]+sum[2*n-i][j];            
        }
        printf("Case %ld: %ld\n",cs++,sum[2*n-1][1]);           
    }
    return 0;
}
