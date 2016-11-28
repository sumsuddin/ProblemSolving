#include<stdio.h>
long long t,cs=1,n;
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
        scanf("%lld",&n);
        
        if(n%9)
        printf("Case %lld: %lld\n",cs++,n+(n/9));
        else
        {
            n+=(n/9);
            printf("Case %lld: %lld %lld\n",cs++,n-1,n);
        }
	}
	return 0;
}
