#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<long>vc[10000],wt[10000];
bool flag;
struct chk
{
	long node;
	long cost;

	bool operator < (const chk& X) const
	{
		return X.cost<cost;
	}
}nod;

priority_queue<chk>pque;
long t,i,vs[10000],n,m,a,b,w,cs=1;
long ans1,ans2,cst;

void dij()
{
	while(!pque.empty())
	{
		nod=pque.top();
		pque.pop();
		a=nod.node;
		cst=nod.cost;
		vs[a]++;

		if(a==n)
		{
			if(flag)
			{
				flag=0;
				ans1=cst;
			}
			else if(ans1<cst && ans2>cst)
				ans2=cst;
		}

		for(long i=0;i<vc[a].size();i++)
			if(vs[vc[a][i]]<2)
			{
				nod.node=vc[a][i];
				nod.cost=cst+wt[a][i];
				pque.push(nod);
			}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=1;i<=n;i++)
			vs[i]=0,vc[i].clear(),wt[i].clear();


		while(m--)
		{
			scanf("%ld%ld%ld",&a,&b,&w);

			vc[a].push_back(b);
			wt[a].push_back(w);

			vc[b].push_back(a);
			wt[b].push_back(w);
		}
		nod.cost=0;
		nod.node=1;
		pque.push(nod);

		ans1=-1;
		ans2=1000000000;
		flag=1;

		dij();
		printf("Case %ld: %ld\n",cs++,ans2);
	}
	return 0;
}
