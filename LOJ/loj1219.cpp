#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[10050];
long a,d,sum,cnt[10050],now,n,t,i,cs=1;
bool vs[10050];
long rec(long a)
{
	vs[a]=0;
	long i,all=cnt[a];
	for(i=0;i<vc[a].size();i++)
	{
		if(vs[vc[a][i]])
		all+=rec(vc[a][i]);
	}
	sum+=(all-1)<0?-(all-1):(all-1);
	return all-1;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
		{
			vs[i+1]=1;
			scanf("%ld",&now);
			scanf("%ld%ld",&cnt[now],&d);
			while(d--)
				scanf("%ld",&a),vc[now].push_back(a),vc[a].push_back(now);
		}
		sum=0;
		vs[1]=0;
		rec(1);
		for(i=0;i<=n;i++)
			vc[i].clear();
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}