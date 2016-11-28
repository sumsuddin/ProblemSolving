#include<stdio.h>
long n,t,l,h,mid,cs=1;

long chk(long p)
{
	long sum=0;
	while(p>0)
		sum+=p/5,p/=5;
	return sum;
}

long search(long h)
{
	l=0;
	while(l<h)
	{
		mid=(l+h)/2;
		
		if(chk(mid)>=n)
			h=mid;
		else
			l=mid+1;
		mid=(l+h)/2;
	}
	return mid;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		mid=search(n*5);
		if(chk(mid)==n)
			printf("Case %ld: %ld\n",cs++,mid);
		else
			printf("Case %ld: impossible\n",cs++);
	}
	return 0;
}