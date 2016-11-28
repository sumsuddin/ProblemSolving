#include<stdio.h>
#include<algorithm>
using namespace std;
long i,t,n,j,cs=1;
struct ss
{
	long cnt,vlu;
}
sr[1050];

bool cmp(ss a, ss b)
{
	if(a.cnt==b.cnt)
		return a.vlu>b.vlu;
	else
		return a.cnt<b.cnt;
}

int main()
{
	for(i=1;i<1001;i++)
		sr[i].cnt=1;

	sr[1].vlu=1;
	for(i=2;i<=1000;i++)
	{
		sr[i].vlu=i;
		for(j=i;j<=1000;j+=i)
			sr[j].cnt++;
	}
	sort(sr+1,sr+1001,cmp);

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);

		printf("Case %ld: %ld\n",cs++,sr[n].vlu);
	}
	return 0;
}