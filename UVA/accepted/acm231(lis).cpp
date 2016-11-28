#include<stdio.h>

long i,l,u,size,mid,n,stak[1000050],cs=1;
bool flag;
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
			if(stak[mid]<n)
				u=mid-1;
			else
				if(stak[mid]>n)
					l=mid+1;
	}
	return mid;
}

void insert(long a)
{
	if(stak[size-1]>a)
		stak[size++]=a;
	else
	{
		bsearch(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]>=a && mid<size)
			mid++;
		stak[mid]=a;
	}
}

int main()
{
	while(~scanf("%ld",&n) && n>=0)
	{
		stak[0]=n;
		size=1;
		while(scanf("%ld",&n)&& n>=0)
		{
			insert(n);
		}
		if(flag)
			printf("\n");
		else
			flag=1;
		printf("Test #%ld:\n  maximum possible interceptions: %ld\n",cs++,size);
	}
	return 0;
}