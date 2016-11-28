#include<stdio.h>
#include<string.h>
#include<memory.h>
#define swap(m,n) m^=n^=m^=n
long i,n,tree[1000010],a[1000010],raw,bacup,left[1000010],right[1000010],state[1000010],p,q,cs=1;
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
		tree[pos]=tree[pos*2]+tree[pos*2+1];
	}
}

long range(long l,long h,long pos)
{
	if(h<left[pos] || l>right[pos])
		return 0;
	else if(l<=left[pos] && h>=right[pos])
		return tree[pos];
	else
	{
		return range(l,h,pos*2)+range(l,h,pos*2+1);
	}
}

void update(long p,long q)
{
	tree[state[p]]=q;

	raw=state[p]/2;

	
	while(raw)
	{
		tree[raw]=(tree[raw*2]+tree[raw*2+1]);
		raw/=2;
	}
}

int main()
{
	while(scanf("%ld",&n),n)
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		build(1,n,1);
		getchar();
		if(cs>1)
			printf("\n");
		printf("Case %ld:\n",cs++);
		while(scanf("%c",&c))
		{			
			if(c=='S')
			{
				scanf("%ld%ld",&p,&q);
				update(p,q);
			}
			else if(c=='M')
			{
				scanf("%ld%ld)",&p,&q);
				printf("%ld\n",range(p,q,1));
			}
			else
			{
				scanf("%*c%*c");
				break;
			}
			getchar();
		}
	}
	return 0;
}