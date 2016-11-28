#include<stdio.h>
long i,left[300005],right[300005],tree[300005][10],dir,p,q,n,qua,t,full[300005],cs=1,j;

void one(long pos)
{
	long ll;
	ll=tree[pos][2];
	tree[pos][2]=tree[pos][1];
	tree[pos][1]=tree[pos][0];
	tree[pos][0]=ll;
}

void two(long pos)
{
	long ll;
	ll=tree[pos][2];
	tree[pos][2]=tree[pos][0];
	tree[pos][0]=tree[pos][1];
	tree[pos][1]=ll;
}

void build(long l,long h,long pos)
{
	left[pos]=l;right[pos]=h;
	if(l==h)
	{
		full[pos]=0;
		tree[pos][1]=tree[pos][2]=0;
		tree[pos][0]=1;
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		for(i=0;i<3;i++)
			tree[pos][i]=tree[pos*2][i]+tree[pos*2+1][i];
		full[pos]=0;
	}
}

void update(long l,long h,long pos)
{
	if(h<left[pos] || l>right[pos])
		return;
	else if(l<=left[pos] && h>=right[pos])
	{
		full[pos]++;
		one(pos);
	}
	else
	{
		update(l,h,pos*2);
		update(l,h,pos*2+1);

		for(i=0;i<3;i++)
			tree[pos][i]=tree[pos*2][i]+tree[pos*2+1][i];

		if(full[pos]%3==1)
			one(pos);
		else if(full[pos]%3==2)
			two(pos);
	}
}

long ret(long dir,long pos)
{
	if(dir%3==1)
		return tree[pos][2];
	else if(dir%3==2)
		return tree[pos][1];
	else if(dir%3==0)
		return tree[pos][0];

	return 0;
}

long range(long dir,long l,long h,long pos)
{
	if(h<left[pos] || l>right[pos])
		return 0;
	else if(l<=left[pos] && h>=right[pos])
		return ret(dir,pos);
	else
		return range(dir+full[pos],l,h,pos*2)+range(dir+full[pos],l,h,pos*2+1);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&qua);

		build(0,n-1,1);
		printf("Case %ld:\n",cs++);

		while(qua--)
		{
			scanf("%ld%ld%ld",&dir,&p,&q);
			if(dir==0)
				update(p,q,1);
			else
				printf("%ld\n",range(0,p,q,1));
		}
	}
	return 0;
}