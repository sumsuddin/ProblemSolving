#include<stdio.h>
long a[100050],s1,s2,s,e,cs=1,l,h,mid,q,n,t,i;
long search(long p)
{
	l=0;h=n-1;

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
		scanf("%ld%ld",&n,&q);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		printf("Case %ld:\n",cs++);

		while(q--)
		{
			scanf("%ld%ld",&s,&e);
			s1=search(s);
			s2=search(e);
			while(a[s1]<s && s1<n)
				s1++;
			while(a[s2+1]<e && s2+1<n)
				s2++;
			if(a[s2]>e)
				s2--;
			printf("%ld\n",s2-s1+1);
		}
	}
	return 0;
}