#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
vector<long>vc[1000050];
queue<long>stk,que;
long i,print,n,indeg[1000050],eg,a,b,time;

void topsort()
{
	time=0;
	for(i=1;i<=n;i++)
		if(indeg[i]==0)
			stk.push(i);

	while(!stk.empty())
	{
		print=stk.front();
		que.push(print);
		time++;
		stk.pop();

		for(i=0;i<vc[print].size();i++)
		{
			indeg[vc[print][i]]--;
			if(indeg[vc[print][i]]==0)
				stk.push(vc[print][i]);
		}
	}
}

int main()
{
	while(~scanf("%ld%ld",&n,&eg))
	{
		for(i=0;i<=n;i++)
			indeg[i]=0;
		for(i=0;i<eg;i++)
		{
			scanf("%ld%ld",&a,&b);
			vc[a].push_back(b);
			indeg[b]++;
		}
		topsort();

		if(time==n)
		{
			while(!que.empty())
				printf("%ld\n",que.front()),que.pop();
		}
		else
		{
			while(!que.empty())
				que.pop();
			printf("IMPOSSIBLE\n");
		}
		for(i=0;i<=n;i++)
			vc[i].clear();
	}
	return 0;
}