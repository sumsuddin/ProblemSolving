#include<stdio.h>
#include<algorithm>
using namespace std;
long a[2050],n,i,j,mid,sum,t,cs=1;

long bs(long p, long l,long h)
{
	while(l<=h)
	{
		mid=(l+h)/2;

		if(a[mid]==p)
			return mid;
		else if(a[mid]<p)
			l=mid+1;
		else
			h=mid-1;
	}
	return mid;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		sort(a,a+n);

		sum=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				mid=bs(a[i]+a[j],j+1,n-1);
				while(a[mid]<a[i]+a[j] && mid<n)
					mid++;
				sum+=mid-j-1;
			}
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}