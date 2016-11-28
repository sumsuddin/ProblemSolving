#include<stdio.h>
long i,t,a[1000050],path[1000050],stak[1000050],size,mid,l,u,lis[1000050],sav[1000050];
bool flag=1;
char st[100];
long bsearch(long value)
{
	mid=0;
	l=1;u=size-1;
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
	{
		sav[size]=i,stak[size]=a,mid=size;
		size++;
	}
	else
	{
		bsearch(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]<=a && mid<size)
			mid++;
		stak[mid]=a;
		sav[mid]=i;
	}
}

void prin(long i)
{
	if(path[i]>-1)
		prin(path[i]);
	printf("%ld\n",a[i]);
}

int main()
{
	sav[0]=0;
	scanf("%ld",&t);
	getchar();
	getchar();
	while(t-- && gets(st))
	{
		sscanf(st,"%ld",&a[0]);
		stak[1]=a[0];
		size=2;
		lis[0]=1;
		path[0]=-1;

		for(i=1;gets(st) && st[0];i++)
		{
			sscanf(st,"%ld",&a[i]);
			insert(a[i]);
			if(mid==1)
				path[i]=-1;
			else
				path[i]=sav[mid-1];
			lis[i]=mid;
		}
		if(flag)
			flag=0;
		else
			printf("\n");

		printf("Max hits: %ld\n",size-1);

		while(i--)
			if(lis[i]==size-1)
			{
				prin(i);
				break;
			}
	}
	return 0;
}