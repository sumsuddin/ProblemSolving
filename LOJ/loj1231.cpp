#include<cstdio>
long a[7500],mx,k,d,t,kp,cs=1;
long b[105];
long count[105];
int main()
{
   
    long n,i,j;
 
    scanf("%ld",&t);
 
    while(t--)
    {
        mx=0;
        scanf("%ld%ld",&n,&kp);
 
        for(i=0;i<n;i++)
            scanf("%ld",&b[i]);
 
        for(i=0;i<n;i++)
            scanf("%ld",&count[i]);
 
        for(i=0;i<=kp;i++)
            a[i]=0;
 
        a[0]=1;
 
        for(j=0;j<n;j++)
        {
          for(k=mx;k>=0;k--)
          {
             if(a[k])
             {
               d=count[j];
               for(i=k+b[j];i<=kp && d--;i+=b[j])
               {
                    a[i]=(a[i]+a[k])%100000007;
                    if(i>mx)
                       mx=i;
              }
             }
          }
        }
        printf("Case %ld: %ld\n",cs++,a[kp]%100000007);
    }
    return 0;
}