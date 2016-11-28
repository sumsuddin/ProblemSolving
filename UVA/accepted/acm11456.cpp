#include<stdio.h>
long i,a[2050],lis[2050],lds[2050],l,u,mid,stak[2050],size,t,n;
long bsearch(long value)
{
	mid=0;
	l=0;u=size-1;
	while(u>=l)
	{
		mid=(l+u)/2;
		if(stak[mid]==value)
			return mid;
		else
			if(stak[mid]<value)
				l=mid+1;
			else
				if(stak[mid]>value)
					u=mid-1;
	}
	return mid;
}

long search(long value)
{
	mid=0;
	l=0;u=size-1;
	while(u>=l)
	{
		mid=(l+u)/2;
		if(stak[mid]==value)
			return mid;
		else
			if(stak[mid]>value)
				l=mid+1;
			else
				if(stak[mid]<value)
					u=mid-1;
	}
	return mid;
}

void ins(long a)
{
	if(stak[size-1]<a)
		stak[size++]=a,mid=size-1;
	else
	{
		bsearch(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]<=a && mid<size)
			mid++;
		stak[mid]=a;
	}
}

void dis(long a)
{
	if(stak[size-1]>a)
		stak[size++]=a,mid=size-1;
	else
	{
		search(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]>=a && mid<size)
			mid++;
		stak[mid]=a;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		if(n==0)
		{
			printf("0\n");
			continue;
		}


		for(i=0;i<n;i++)
			scanf("%ld",&a[i]),lis[i]=lds[i]=0;

		stak[0]=a[n-1];
		size=1;
		lis[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			ins(a[i]);
			lis[i]=mid;
		}
		stak[0]=a[n-1];
		size=1;
		lds[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			dis(a[i]);
			lds[i]=mid;
		}
		mid=0;
		for(i=0;i<n;i++)
			if(lis[i]+lds[i]+1>mid)
				mid=lis[i]+lds[i]+1;
		printf("%ld\n",mid);
	}
	return 0;
}
