#include<stdio.h>
#include<algorithm>
using namespace std;
long long cs=1,i,a[100010],sm[100010],st,k,c,t,n;
int main()
{
 	scanf("%lld",&t);
 	
 	while(t--)
 	{
	 	scanf("%lld%lld%lld%lld",&k,&c,&n,&a[0]);
		sm[0]=0;
		for(i=1;i<n;i++)
		{
		     a[i]=(a[i-1]*k+c)%1000007;
		     
	   }
	   sort(a,a+n);
	   sm[0]=a[0];
	   for(i=1;i<n;i++)
	   sm[i]=sm[i-1]+a[i];
	   st=0;
	   for(i=0;i<n-1;i++)
            st+=(sm[n-1]-sm[i])-(a[i]*(n-i-1));  
       printf("Case %lld: %lld\n",cs++,st);          			
    }
    return 0;
}
