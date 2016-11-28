#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[110],wt[110],inv[110];
long i,n,t,a,b,w,sum,mn,cs=1;

void dfs(long src,long cld)
{
	if(cld==1)
		return;
	if(vc[cld].size()==0)
	{
		if(inv[cld][0]==src)
		{
			sum+=wt[cld][1];
			dfs(cld,inv[cld][1]);
		}
		else
		{
			sum+=wt[cld][0];
			dfs(cld,inv[cld][0]);
		}
	}
	else if(vc[cld].size()==1)
	{
		if(vc[cld][0]==src)
		{
			sum+=wt[cld][0];
			dfs(cld,inv[cld][0]);
		}
		else
			dfs(cld,vc[cld][0]);
	}
	else
	{
		if(vc[cld][0]==src)
			dfs(cld,vc[cld][1]);
		else
			dfs(cld,vc[cld][0]);
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			vc[a].push_back(b);
			inv[b].push_back(a);
			wt[b].push_back(w);
		}

		sum=0;
		if(vc[1].size()==0)
		{
			sum=wt[1][0];
			dfs(1,inv[1][0]);
			mn=sum;

			sum=wt[1][1];
			dfs(1,inv[1][1]);
			if(mn>sum)
				mn=sum;
		}
		else if(vc[1].size()==1)
		{
			sum=0;
			dfs(1,vc[1][0]);
			mn=sum;
			sum=wt[1][0];
			dfs(1,inv[1][0]);
			if(mn>sum)
				mn=sum;
		}
		else
		{
			sum=0;
			dfs(1,vc[1][0]);
			mn=sum;
			sum=0;
			dfs(1,vc[1][1]);
			if(mn>sum)
				mn=sum;
		}
		printf("Case %ld: %ld\n",cs++,mn);
		for(i=0;i<=n;i++)
			vc[i].clear(),wt[i].clear(),inv[i].clear();
	}
	return 0;
}