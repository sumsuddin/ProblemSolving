#include<stdio.h>
#include<vector>
using namespace std;

vector<long>vc[1050];
long i,t,n,k,a,b,tim[1050],time,cs=1;
bool tru,vs[1050],ccs[1050];

void rec(long p)
{
	ccs[p]=0;

	for(long i=0;i<vc[p].size();i++)
		if(ccs[vc[p][i]])
			time++,rec(vc[p][i]);
	tim[p]=++time;
}

void call(long p)
{
	ccs[p]=0;

	long i,mx=-1,ind;

	for(i=0;i<vc[p].size();i++)
		if(ccs[vc[p][i]] && tim[vc[p][i]]>mx)
			mx=tim[vc[p][i]],ind=vc[p][i];
	if(mx!=-1)
		call(ind);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		for(i=0;i<1001;i++)
			tim[i]=0,vs[i]=0,vc[i].clear();

		scanf("%ld",&n);

		while(n--)
		{
			scanf("%ld",&k);

			while(k--)
			{
				scanf("%ld%ld",&a,&b);
				vs[a]=vs[b]=1;
				vc[a].push_back(b);
			}
		}
		for(i=0;i<1001;i++)
			ccs[i]=vs[i];

		time=0;

		for(i=0;i<1001;i++)
			if(ccs[i])
				time++,rec(i);

		for(i=0;i<1001;i++)
			ccs[i]=vs[i];

		call(0);

		tru=1;
		for(i=0;i<1001;i++)
			if(ccs[i])
			{
				tru=0;
				break;
			}
		if(tru)
			printf("Case %ld: YES\n",cs++);
		else
			printf("Case %ld: NO\n",cs++);
	}
	return 0;
}