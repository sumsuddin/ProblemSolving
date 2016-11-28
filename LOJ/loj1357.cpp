#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[100005];
long i,n,t,a,b,sum,cs=1,cnt[100005],cc[100005];
long dfs(long nd)
{
	if(vc[nd].size()==0)
		return 1;
	long i;
	for(i=0;i<vc[nd].size();i++)
		cc[vc[nd][i]]=0,cnt[vc[nd][i]]=dfs(vc[nd][i]);
	
	cc[vc[nd][i-1]]=cnt[vc[nd][i-1]];
	for(i=vc[nd].size()-1;i>0;i--)
		cc[vc[nd][i-1]]=cc[vc[nd][i]]+cnt[vc[nd][i-1]];

	for(i=0;i<vc[nd].size();i++)
		sum+=(cc[vc[nd][i]]-cnt[vc[nd][i]])*cnt[vc[nd][i]];
	return cc[vc[nd][0]]+1;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<n;i++)
			scanf("%ld%ld",&a,&b),vc[a].push_back(b);

		sum=0;

		dfs(1);
		printf("Case %ld: %ld %ld\n",cs++,n-1,sum);
		for(i=0;i<=n;i++)
			vc[i].clear();
	}
	return 0;
}
