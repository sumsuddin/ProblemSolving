#include<stdio.h>

long i,l,u,size,mid,n,stak[100],ind[100],st[100],a;

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

void insert(long a)
{
	if(stak[size-1]<a)
		stak[size++]=a;
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

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&ind[i]);
		while(~scanf("%ld",&a))
		{
			st[ind[0]]=a;
			for(i=1;i<n;i++)
				scanf("%ld",&st[ind[i]]);

			stak[0]=st[1];
			size=1;
			for(i=2;i<=n;i++)
				insert(st[i]);
			printf("%ld\n",size);
		}
	}
	return 0;
}