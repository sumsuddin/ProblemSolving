#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[1050];
long k,n,m,t,a[150],sum,cs=1,cnt[1050],i,b,c,nw[1050],lst;
bool vst[1050];
void rec(long a)
{
	for(long i=0;i<vc[a].size();i++)
	{
		if(vst[vc[a][i]])
		{
			nw[lst++]=vc[a][i];
			vst[vc[a][i]]=0;
			cnt[vc[a][i]]++;
			if(cnt[vc[a][i]]==k)
				sum++;
			rec(vc[a][i]);
		}
	}
}


int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&k,&n,&m);

		sum=0;
		for(i=0;i<k;i++)
			scanf("%ld",a+i);

		for(i=1;i<=n;i++)
			vst[i]=1,cnt[i]=0;

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&b,&c);

			vc[b].push_back(c);
		}
		lst=0;
		for(i=0;i<k;i++)
		{
			vst[a[i]]=0;
			lst=0;
			cnt[a[i]]++;
			if(cnt[a[i]]==k)
				sum++;
			rec(a[i]);
			vst[a[i]]=1;
			while(lst--)
				vst[nw[lst]]=1;
		}
		for(i=0;i<=n;i++)
			vc[i].clear();
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}