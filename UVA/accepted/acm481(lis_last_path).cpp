#include<stdio.h>

long i,l,u,size,mid,n,stak[1000050],cs=1,prin[1000050],par[1000050],vlu[1000050],ind[1000050];
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
			if(stak[mid]>value)
				u=mid-1;
			else
				if(stak[mid]<value)
					l=mid+1;
	}
	return mid;
}

void insert(long a)
{
	if(stak[size-1]<a)
	{
		par[i]=ind[size-1];
		ind[size]=i;
		stak[size++]=a;
	}
	else
	{
		bsearch(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]<=a && mid<size)
			mid++;
		stak[mid]=a;

		if(mid==0)
			par[i]=-1;
		else
			par[i]=ind[mid-1];
		ind[mid]=i;
	}
}

int main()
{
	while(~scanf("%ld",&n))
	{
		vlu[0]=n;
		n=1;
		while(~scanf("%ld",&vlu[n]))
			n++;

		stak[0]=vlu[0];
		size=1;
		ind[0]=0;
		par[0]=-1;
		for(i=1;i<n;i++)
		{
			insert(vlu[i]);
		}
		i=0;
		n=ind[size-1];
		while(1)
		{
			prin[i++]=vlu[n];
			if(par[n]==-1)
				break;
			else
				n=par[n];
		}
		printf("%ld\n-\n",size);
		while(i--)
			printf("%ld\n",prin[i]);
	}
	return 0;
}