#include<stdio.h>
long stak[100050],mid,u,l,lst,lis[100050],lds[100050],n,a[100050],i,t,cs=1;
long bsearch(long value)
{
	mid=0;
	l=1;u=lst-1;
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
	if(stak[lst-1]<a)
		stak[lst++]=a,mid=lst-1;
	else
	{
		bsearch(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]<=a && mid<lst)
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
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		stak[1]=a[0];
		lst=2;
		lis[0]=1;

		for(i=1;i<n;i++)
		{
			insert(a[i]);
			lis[i]=mid;
		}
		stak[1]=a[n-1];
		lst=2;
		lds[n-1]=1;
		for(i=n-2;i>=0;i--)
		{
			insert(a[i]);
			lds[i]=mid;
		}
		lst=0;
		for(i=0;i<n;i++)
			if(lis[i]<lds[i] && (lis[i]*2)-1>lst)
				lst=(lis[i]*2)-1;
			else if(lis[i]>=lds[i] && (lds[i]*2)-1>lst)
				lst=(lds[i]*2)-1;
		printf("Case %ld: %ld\n",cs++,lst);
			
	}
	return 0;
}
