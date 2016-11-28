#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
long i,n,tree[1100010],raw,bacup,lft[1100010],rght[1000010],p,q,prx[100050],len[100050],cm[100050],t,qury,cs=1;
char st[100050];
struct sr
{
	string ss;
	long ind;
}node[100050];

bool cmp(sr aa,sr bb)
{
	if((aa.ss).compare(bb.ss)>0)
		return 1;
	else
		return 0;
}

void build(long l,long h,long pos)
{
	lft[pos]=l;rght[pos]=h;
	if(l==h)
		tree[pos]=len[l];
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		tree[pos]=tree[pos*2]<tree[pos*2+1]?tree[pos*2]:tree[pos*2+1];
		if(tree[pos]>cm[(l+h)/2])
			tree[pos]=cm[(l+h)/2];
	}
}

long range(long l,long h,long pos)
{
	long p,q;
	if(h<lft[pos] || l>rght[pos])
		return 1000000000;
	else if(l<=lft[pos] && h>=rght[pos])
		return tree[pos];
	else
	{
		p=q=1000000000;
		p=range(l,h,pos*2);
		q=range(l,h,pos*2+1);
		if(l<=(lft[pos]+rght[pos])/2 && (lft[pos]+rght[pos])/2+1<=h)
			if(p>cm[(lft[pos]+rght[pos])/2])
				p=cm[(lft[pos]+rght[pos])/2];
	}
	if(p>q)
		return q;
	else
		return p;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%s",st);
			node[i].ss=st;
			node[i].ind=i;
		}
		st[0]=0;
		node[i].ss=st;

		sort(node+1,node+n+1,cmp);

		for(i=1;i<=n;i++)
			prx[node[i].ind]=i;

		for(i=1;i<=n;i++)
		{
			len[i]=(node[i].ss).length();
			p=0;
			while(node[i].ss[p]==node[i+1].ss[p] && node[i].ss[p])
				p++;
			cm[i]=p;
		}

		build(1,n,1);
		scanf("%ld",&qury);
		printf("Case %ld:\n",cs++);
		while(qury--)
		{
			scanf("%ld%ld",&p,&q);
			p=prx[p];
			q=prx[q];
			if(p>q)
			{
				i=p;
				p=q;
				q=i;
			}
			printf("%ld\n",range(p,q,1));
		}
	}
	return 0;
}