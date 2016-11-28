#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[1050];
long i,t,n,m,p,q,sum,a[1050],avg,cs=1;
bool flag,vst[1050];
void dfs(long x)
{
	long i;
	sum+=a[x-1];
	for(i=0;i<vc[x].size();i++)
		if(vst[vc[x][i]])
		{
			vst[vc[x][i]]=0;
			p++;
			dfs(vc[x][i]);
		}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		sum=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]),sum+=a[i],vst[i+1]=1,vc[i+1].clear();

		if(sum%n)
			flag=0;
		else
			avg=sum/n;

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&p,&q);
			vc[p].push_back(q);
			vc[q].push_back(p);
		}

		flag=1;
		for(i=1;i<=n && flag;i++)
		{
			if(vst[i])
			{
				sum=0;
				p=1;
				vst[i]=0;
				dfs(i);
				if(sum%p || sum/p!=avg)
					flag=0;
			}
		}
		if(flag)
			printf("Case %ld: Yes\n",cs++);
		else
			printf("Case %ld: No\n",cs++);
	}
	return 0;
}