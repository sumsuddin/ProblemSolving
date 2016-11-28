#include<stdio.h>
#include<string.h>
#include<memory.h>
#define swap(m,n) m^=n^=m^=n
long i,n,tree[1000010],a[1000010],raw,bacup,left[1000010],right[1000010],state[1000010],p,q,qury;
char c;
void build(long l,long h,long pos)
{
	left[pos]=l;right[pos]=h;
	if(l==h)
	{
		tree[pos]=a[l];
		state[l]=pos;
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		tree[pos]=tree[pos*2]<tree[pos*2+1]?tree[pos*2]:tree[pos*2+1];
	}
}

long range(long l,long h,long pos)
{
	long p,q;
	if(h<left[pos] || l>right[pos])
		return 1000000000;
	else if(l<=left[pos] && h>=right[pos])
		return tree[pos];
	else
	{
		p=q=-1;
		p=range(l,h,pos*2);
		q=range(l,h,pos*2+1);
	}
	if(p>q)
		return q;
	else
		return p;
}

void update(long p,long q)
{
	swap(tree[state[p]],tree[state[q]]);
	raw=state[p]/2;

	
	while(raw)
	{
		tree[raw]=(tree[raw*2]<tree[raw*2+1])?tree[raw*2]:tree[raw*2+1];
		raw/=2;
	}
	raw=state[q]/2;

	
	while(raw)
	{
		tree[raw]=(tree[raw*2]<tree[raw*2+1])?tree[raw*2]:tree[raw*2+1];
		raw/=2;
	}
}

int main()
{
	while(~scanf("%ld%ld",&n,&qury))
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		build(1,n,1);
		while(qury--)
		{
			getchar();
			scanf("%c%*c%*c%*c%*c%*c",&c);
			if(c=='s')
			{
				scanf("%ld%c",&p,&c);
				bacup=p;
				while(scanf("%ld%c",&q,&c))
				{
					update(p,q);
					p=q;
					if(c==')')
						break;
				}
			}
			else
			{
				scanf("%ld,%ld)",&p,&q);
				printf("%ld\n",range(p,q,1));
			}
		}
	}
	return 0;
}