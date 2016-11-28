#include<stdio.h>
long i,r,c,x[100005],y[100005],t,q,mid,mm,ll,hh,cnt[100005],w[100005],cs=1;
long count(long a[],long pnt)
{
	long i,sum=0;
	for(i=0;i<=q;i++)
		sum+=((a[i]>pnt)?a[i]-pnt:pnt-a[i])*w[i];
	return sum;
}

long check(long a[],long l,long h)
{
	if(l==h)
		return l;
	
	ll=count(a,l);

	hh=count(a,h);

	mid=(l+h)/2;

	mm=count(a,mid);

	if(ll>hh)
	{
		if(mm<hh)
			return check(a,mid,h-1);
		else if(mid<h)
			return check(a,mid+1,h);
		else
			return check(a,mid,h);
	}
	else
	{
		if(mm<ll)
			return check(a,l+1,mid);
		else if(l<mid)
			return check(a,l,mid-1);
		else
			return check(a,l,mid);
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&r,&c,&q);

		for(i=0;i<=r;i++)
			cnt[i]=-1;
		for(i=0;i<q;i++)
			scanf("%ld%ld%ld",&x[i],&y[i],&w[i]);

		printf("Case %ld: ",cs++);

		printf("%ld ",check(x,1,r));

		for(i=0;i<=c;i++)
			cnt[i]=-1;

		printf("%ld\n",check(y,1,c));
	}
	return 0;
}