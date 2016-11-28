#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[110];
long cl[110],vst[3][110],i,n,a,b,m,sum,cs=1,t;
bool flag;
void bcl(long st,long p)
{
	long i;
	if(p)
	{
		if(flag)
			flag=0;
		else
			cl[st]=p;
	}
	for(i=0;i<vc[st].size();i++)
	{
		if(vst[!p][vc[st][i]])
		{
			vst[!p][vc[st][i]]=0;
			bcl(vc[st][i],!p);
		}
	}
}


int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		sum=0;
		flag=1;
		scanf("%ld%ld",&n,&m);

		for(i=1;i<=n;i++)
			cl[i]=0,vst[1][i]=vst[0][i]=1,vc[i].clear();

		while(m--)
		{
			scanf("%ld%ld",&a,&b);

			vc[a].push_back(b);
			vc[b].push_back(a);
		}
		bcl(1,1);
		for(i=1;i<=n;i++)
			sum+=cl[i];
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}