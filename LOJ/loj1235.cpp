#include<stdio.h>
#include<algorithm>
using namespace std;
long i,j,t,a[20],p[1000000],q[1000000],l,h,lst,lst1,n,k,mid,m,cs=1;
bool flag;
bool bs(long p)
{
	l=0;h=lst1;

	while(l<=h)
	{
		mid=(l+h)/2;
		if(q[mid]==p)
			return 1;
		else if(q[mid]<p)
			l=mid+1;
		else
			h=mid-1;
	}
	return 0;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		m=n/2;

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		lst=1;
		p[0]=0;
		for(i=0;i<m;i++)
			for(j=lst-1;j>=0;j--)
				p[lst++]=p[j]+a[i],p[lst++]=p[j]+2*a[i];

		lst1=1;
		q[0]=0;
		for(i=m;i<n;i++)
			for(j=lst1-1;j>=0;j--)
				q[lst1++]=q[j]+a[i],q[lst1++]=q[j]+2*a[i];

		sort(q,q+lst1);

		flag=1;
		for(i=0;i<lst;i++)
		{
			if(bs(k-p[i]))
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("Case %ld: No\n",cs++);
		else
			printf("Case %ld: Yes\n",cs++);
	}
	return 0;
}