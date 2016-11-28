#include<stdio.h>
long long large,st[10100],sy[10100],i,m,n,sw,pp,qq;

void swap(long long *a,long long *b)
{
	sw=*a;
	*a=*b;
	*b=sw;
}

void maxheap( long long i,long long n)
{
	large=i;
	if(i*2<=n && sy[i*2]<sy[large])
		large=i*2;
	else if(i*2<=n && sy[i*2]==sy[large])
	{
		pp=st[i*2]%2;
		qq=st[large]%2;
		if(pp<0)
			pp*=-1;
		if(qq<0)
			qq*=-1;

		if(pp!=qq)
		{
			if(st[large]%2==0)
				large=i*2;
		}
		else
		{
			if(st[large]%2==0)
			{
				if(st[i*2]<st[large])
					large=i*2;
			}
			else
			{
				if(st[i*2]>st[large])
					large=i*2;
			}

		}
	}
	if(i*2+1<=n && sy[i*2+1]<sy[large])
		large=i*2+1;
	else if(i*2+1<=n && sy[i*2+1]==sy[large])
	{
		pp=st[i*2+1]%2;
		qq=st[large]%2;
		if(pp<0)
			pp*=-1;
		if(qq<0)
			qq*=-1;

		if(pp!=qq)
		{
			if(st[large]%2==0)
				large=i*2+1;
		}
		else
		{
			if(st[large]%2==0)
			{
				if(st[i*2+1]<st[large])
					large=i*2+1;
			}
			else
			{
				if(st[i*2+1]>st[large])
					large=i*2+1;
			}

		}
	}

	if(large!=i)
	{
		swap(&st[i],&st[large]);
		swap(&sy[i],&sy[large]);
		maxheap(large,n);
	}
}

void heapsort(long long n)
{
	swap(&st[1],&st[n]);
	swap(&sy[1],&sy[n]);
	maxheap(1,n-1);
	if(n>1)
	heapsort(n-1);
}

int main()
{
	while(scanf("%lld%lld",&n,&m) && (n||m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&st[i]);
			sy[i]=st[i]%m;
		}

		for(i=n/2;i>0;i--)
		{
			maxheap(i,n);
		}

		heapsort(n);

		printf("%lld %lld\n",n,m);
		for(i=n;i>0;i--)
			printf("%lld\n",st[i]);
	}
	printf("0 0\n");


	return 0;
}
