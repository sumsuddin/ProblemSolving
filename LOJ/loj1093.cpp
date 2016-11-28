#include<stdio.h>
#include<string.h>
#include<memory.h>
#define swap(m,n) m^=n^=m^=n
long i,n,left[300050],right[300050],cs=1,t,a[300050],pol[300050],full[300050],d,mn,mx,mxd;
void build(long l,long h,long pos)
{
	left[pos]=l;right[pos]=h;
	if(l==h)
	{
		pol[pos]=a[l];
		full[pos]=a[l];
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);

		if(pol[pos*2]<pol[pos*2+1])
			pol[pos]=pol[pos*2];
		else
			pol[pos]=pol[pos*2+1];

		if(full[pos*2]<full[pos*2+1])
			full[pos]=full[pos*2+1];
		else
			full[pos]=full[pos*2];
	}
}

void update(long l,long h,long pos)
{
	if(h<left[pos] || l>right[pos])
		return;
	else if(l<=left[pos] && h>=right[pos])
	{
		if(mn>pol[pos])
			mn=pol[pos];
		if(mx<full[pos])
			mx=full[pos];
	}
	else
	{
		update(l,h,pos*2);
		update(l,h,pos*2+1);
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&d);

		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);

		build(1,n,1);
		mxd=0;
		for(i=1;i<=n-d+1;i++)
		{
			mn=a[i],mx=a[i];
			update(i,i+d-1,1);
			if(mxd<mx-mn)
				mxd=mx-mn;
		}
		printf("Case %ld: %ld\n",cs++,mxd);
	}
	return 0;
}