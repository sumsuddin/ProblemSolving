#include<stdio.h>
#include<algorithm>
using namespace std;
long long sum,mid,l,h,t,n,m,i,j,lst,lst1,p[40000],q[40000],w,a[100];
long cs=1;
long long bsearch(long long p)
{
	l=0;h=lst1;
	while(l<=h)
	{
		mid=(l+h)/2;

		if(l==h)
			return mid;

		if(q[mid]<p)
			l=mid+1;
		else
			h=mid;
	}
	return mid;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&w);

		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);

		m=n/2;

		lst=0;
		p[lst++]=0;
		for(i=m;i<n;i++)
			for(j=lst-1;j>=0;j--)
				p[lst++]=p[j]+a[i];

		lst1=0;
		q[lst1++]=0;
		for(i=0;i<m;i++)
			for(j=lst1-1;j>=0;j--)
				q[lst1++]=q[j]+a[i];

		q[lst1]=1000000000000LL;
		sort(q,q+lst1);

		sum=0;
		for(i=0;i<lst;i++)
		{
			mid=bsearch(w-p[i]);
			while(mid<lst1 && q[mid]<=(w-p[i]))
				mid++;
			sum+=mid;
		}
		printf("Case %ld: %lld\n",cs++,sum);
	}
	return 0;
}
