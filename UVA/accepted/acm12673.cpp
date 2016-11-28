#include<stdio.h>
#include<algorithm>
using namespace std;
long n,m,i,a[1000500],b,sum;
int main()
{
    while(~scanf("%ld%ld",&n,&m))
    {
        sum=0;
        for(i=0;i<n;i++)
        scanf("%ld%ld",&a[i],&b),a[i]-=b;

        sort(a,a+n);

        while(n--)
        {
            if(a[n]>0)
            sum+=3;
            else if(a[n]==0)
            {
                if(m>0)
                sum+=3,m--;
                else
                sum++;
            }
            else
            {
                if(m>-a[n])
                sum+=3,m+=(a[n]-1);
                else if(m==-a[n])
                sum++,m+=a[n];
                else
                break;
            }
        }
        printf("%ld\n",sum);
    }
    return 0;
}
