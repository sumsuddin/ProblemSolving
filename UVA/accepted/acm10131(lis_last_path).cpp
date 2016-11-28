#include<stdio.h>
#include<algorithm>
using namespace std;
struct sss
{
	long w,iq,ind;
}
node[10010];
long i,k,stak[10010],path[10010],prin[10010],size,mid,u,l,n,prx[10010],par[10010],ind[10010];
bool flag;
long bsearch(long value)
{
	mid=0;
	l=0;u=size-1;
	while(u>=l)
	{
		mid=(l+u)/2;
		if(stak[mid]==value)
			return mid;
		else
			if(stak[mid]<value)
				l=mid+1;
			else
				if(stak[mid]>value)
					u=mid-1;
	}
	return mid;
}

void insert(long a)
{
	if(stak[size-1]<a)
	{
		par[prx[i]]=ind[size-1];
		ind[size]=prx[i];
		stak[size++]=a;
	}
	else
	{
		bsearch(a);
		if(stak[mid]==a)
			return;
		while(stak[mid]<=a && mid<size)
			mid++;
		stak[mid]=a;

		if(mid==0)
			par[prx[i]]=-1;
		else
			par[prx[i]]=ind[mid-1];
		ind[mid]=prx[i];
	}
}

bool cmp(sss aa,sss bb)
{
	if(aa.iq<bb.iq)
		return 0;
	else
		return 1;
}

int main()
{
	n=0;
	while(~scanf("%ld%ld",&node[n].w,&node[n].iq))
		node[n].ind=n++;
	sort(node,node+n,cmp);

	for(i=0;i<n;i++)
		prx[i]=node[i].ind+1;

	stak[0]=node[0].w;
	size=1;
	ind[0]=prx[0];
	par[prx[0]]=-1;
	for(i=1;i<n;i++)
	{
		insert(node[i].w);
	}

	i=0;
	n=ind[size-1];
	while(1)
	{
		prin[i++]=n;
		if(par[n]==-1)
			break;
		else
			n=par[n];
	}

	printf("%ld\n",size);
	while(i--)
		printf("%ld\n",prin[i]);
	return 0;
}