#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
struct ss
{
	long s,end;
}
st[50050];

long maxv(long a,long b)
{
	return a>b?a:b;
}

multiset<long>sat;
multiset<long>:: iterator it;
long n,t,i,j,sum,lst,cs=1;
bool cmp(ss a,ss b)
{
	return a.s<b.s;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld%ld",&st[i].s,&st[i].end);

		sort(st,st+n,cmp);

		sat.insert(0);
		sat.insert(st[0].end);

		lst=2;
		j=1;
		it=sat.begin();

		sum=1;

		for(i=1;i<n;i++)
		{
			sat.insert(st[i].end);
			lst++;
			while(++it!=sat.end() && *it<st[i].s)
				j++;
			it--;
			sum=maxv(sum,(lst-j));
		}
		printf("Case %ld: %ld\n",cs++,sum);
		sat.clear();
	}
	return 0;
}