#include<stdio.h>
#include<set>
using namespace std;
set<long>sat;
set<long>::iterator it;
long i,tree[1000050],lft[1000050],rht[1000050],ans,prn,cs=1,a[100050],b[100050],t,n,lst;
void build(long l,long h,long pos)
{
	if(l==h)
	{
		tree[pos]=0;
		lft[pos]=b[l];
		rht[pos]=b[l];
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);

		tree[pos]=tree[pos*2]+tree[pos*2+1];
		lft[pos]=lft[pos*2];
		rht[pos]=rht[pos*2+1];
	}
}

void range(long vlu,long pos)
{
	if(lft[pos]>vlu)
		return;

	if(lft[pos]<vlu && rht[pos]>=vlu)
	{
		range(vlu,pos*2);
		range(vlu,pos*2+1);
		return;
	}

	if(rht[pos]<vlu)
		ans=(ans+tree[pos])%1000000007;
}

void update(long vlu,long pos)
{
	if(lft[pos]>vlu || rht[pos]<vlu)
		return;

	if(lft[pos]<=vlu && rht[pos]>=vlu)
	{
		if(lft[pos]==rht[pos])
			tree[pos]=(tree[pos]+ans)%1000000007;
		else
		{
			update(vlu,pos*2);
			update(vlu,pos*2+1);

			tree[pos]=(tree[pos*2]+tree[pos*2+1])%1000000007;
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]),sat.insert(a[i]);

		lst=1;
		for(it=sat.begin();it!=sat.end();it++)
			b[lst++]=*it;
		
		lst--;

		build(1,lst,1);

		prn=0;

		for(i=0;i<n;i++)
		{
			ans=1;
			range(a[i],1);
			prn=(prn+ans)%1000000007;
			update(a[i],1);
		}
		sat.clear();
		printf("Case %ld: %ld\n",cs++,prn%1000000007);
	}
	return 0;
}