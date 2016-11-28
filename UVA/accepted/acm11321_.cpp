#include<stdio.h>
#include<algorithm>
using namespace std;

struct ss
{
	long vlu,md;
}
st[10050];
long i,n,m;
bool cmp(ss a, ss b)
{
	if(a.md!=b.md)
		return a.md<b.md;
	else if(a.vlu%2==0 && b.vlu%2==0)
		return a.vlu<b.vlu;
	else if(a.vlu%2 && b.vlu%2)
		return a.vlu>b.vlu;
	else if(a.vlu%2)
		return 1;
	else
		return 0;
}


int main()
{
	while(scanf("%ld%ld",&n,&m))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&st[i].vlu),st[i].md=st[i].vlu%m;
		sort(st,st+n,cmp);
		printf("%ld %ld\n",n,m);
		if(n==0 && m==0)
			break;

		for(i=0;i<n;i++)
			printf("%ld\n",st[i].vlu);
	}
	return 0;
}
