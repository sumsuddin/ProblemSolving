#include<stdio.h>
#include<algorithm>
using namespace std;
long a[10005],b[10005],n,r,d,ans,i,j;
int main()
{
	while(scanf("%ld%ld%ld",&n,&d,&r)&&(n|| d||r))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&b[i]);

		sort(a,a+n);
		sort(b,b+n);

		for(i=0,ans=0,j=n-1;i<n;i++,j--)
		{
			a[i]=a[i]+b[j];

			if(a[i]>d)
				ans+=a[i]-d;
		}
		printf("%ld\n",ans*r);
	}
	return 0;
}