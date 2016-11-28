#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
vector<long>vc[10010];
stack<long>que;
long i,j,t,n,m,l,p,q,ll,sum;
bool vst[10010];
void call(long p)
{	if(vst[p])
	que.push(p);
	vst[p]=0;
	while(!que.empty())
	{
		p=que.top();
		que.pop();
		sum++;

		ll=vc[p].size();
		for(j=0;j<ll;j++)
		{
			if(vst[vc[p][j]])
			{
				vst[vc[p][j]]=0;
				que.push(vc[p][j]);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&n,&m,&l);
		for(i=1;i<=n;i++)
		{
			vst[i]=1;
			vc[i].clear();
		}

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&p,&q);
			vc[p].push_back(q);
		}
		sum=0;
		while(l--)
		{
			scanf("%ld",&i);
			call(i);
		}
		printf("%ld\n",sum);
	}
	return 0;
}