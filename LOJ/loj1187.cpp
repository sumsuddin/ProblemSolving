#include<stdio.h>

long tree[2000050],lft[2000050],rht[2000050],a[2000050],t,n,cs=1,ans,i,sum;
bool got;

void build(long l,long h,long pos)
{
	if(l==h)
	{
		tree[pos]=1;
		lft[pos]=l;
		rht[pos]=h;
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);

		tree[pos]=tree[pos*2]+tree[pos*2+1];
		lft[pos]=l;
		rht[pos]=h;
	}
}

void update(long key,long pos)
{
	if(sum+tree[pos]<key)
	{
		sum+=tree[pos];
		return ;
	}
	if(got)
		return;

	if(lft[pos]==rht[pos])
	{
		tree[pos]--;
		ans=lft[pos];
		got=1;
	}
	else
	{
		update(key,pos*2);
		update(key,pos*2+1);

		tree[pos]=tree[pos*2]+tree[pos*2+1];
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);

		build(1,n,1);

		for(i=n;i>0;i--)
		{
			got=0;
			sum=0;
			update(i-a[i],1);
		}

		printf("Case %ld: %ld\n",cs++,ans);
	}
	return 0;
}