#include<stdio.h>
#include<algorithm>
using namespace std;
long i,mid,l,u,size,stak[100050],ans,n;
struct ss
{
    long a,b;
}
sr[100050];

bool cmp(ss p,ss q)
{
    if(p.b==q.b)
    return p.a<q.b;
    else
    return p.b<q.b;
}

bool dmp(ss p,ss q)
{
    if(p.a==q.a)
    return p.b<q.b;
    else
    return p.a<q.a;
}

long bsearch(long value)
{
	mid=0;
	l=0;u=size-1;
	while(u>=l)
	{
		mid=(l+u)/2;
        if(stak[mid]<value)
        l=mid+1;
        else if(stak[mid]>=value)
        u=mid-1;

	}
	return mid;
}

void insert(long a)
{
	if(stak[size-1]<=a)
		stak[size++]=a;
	else
	{
		bsearch(a);
		while(stak[mid]<=a && mid<size)
			mid++;
		stak[mid]=a;
	}
}

int main()
{
    while(scanf("%ld",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%ld%ld",&sr[i].a,&sr[i].b);

        sort(sr,sr+n,cmp);
		stak[0]=sr[0].a;
		size=1;
        for(i=1;i<n;i++)
        insert(sr[i].a);
        ans=size;

        sort(sr,sr+n,dmp);
		stak[0]=sr[0].b;
		size=1;
        for(i=1;i<n;i++)
        insert(sr[i].b);
        if(ans<size)
        ans=size;
        printf("%ld\n",ans);
    }
    printf("*\n");
    return 0;
}
