#include<stdio.h>
#include<string.h>
#include<memory.h>
#define swap(m,n) m^=n^=m^=n
long i,n,tree[1000010],left[1000010],right[1000010],state[1000010],p,q,cs=1,t,a[1000005],inc,qua,dir,pol[1000005],full[1000005];
void build(long l,long h,long pos)
{
	left[pos]=l;right[pos]=h;
	if(l==h)
	{
		tree[pos]=a[l]=0;
		state[l]=pos;
		pol[pos]=full[pos]=0;
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		
		tree[pos]=tree[pos*2]+tree[pos*2+1];
		pol[pos]=full[pos]=0;
	}
}

long update(long l,long h,long pos)
{
	if(h<left[pos] || l>right[pos])
		return 0;
	else if(l<=left[pos] && h>=right[pos])
		return tree[pos]+pol[pos]+(full[pos]*(right[pos]-left[pos]+1));
	else
	{
		long inc=0;
		if(l>=left[pos] && h<=right[pos])
			inc=h-l+1;
		else if(h>right[pos] && l<=right[pos])
			inc=right[pos]-l+1;
		else if(h>=left[pos] && l<left[pos])
			inc=h-left[pos]+1;


		return update(l,h,pos*2)+update(l,h,pos*2+1)+full[pos]*inc;
	}
}

void add(long l,long h,long pos)
{
	if(h<left[pos] || l>right[pos])
		return;
	else if(l<=left[pos] && h>=right[pos])
		full[pos]+=inc;
	else
	{
		add(l,h,pos*2);
		add(l,h,pos*2+1);
		pol[pos]=(((full[pos*2]*(right[pos*2]-left[pos*2]+1))+pol[pos*2])+((full[pos*2+1]*(right[pos*2+1]-left[pos*2+1]+1))+pol[pos*2+1]));
	}
}


int main()
{
	scanf("%ld",&t);
	while(t--)
	{	
		scanf("%ld%ld",&n,&qua);
		printf("Case %ld:\n",cs++);
		build(0,n-1,1);

		while(qua--)
		{
			scanf("%ld",&dir);
			if(dir==0)
			{
				scanf("%ld%ld%ld",&p,&q,&inc);
				add(p,q,1);
			}
			else
			{
				scanf("%ld%ld",&p,&q);
				printf("%ld\n",update(p,q,1));
			}
		}
	}
	return 0;
}