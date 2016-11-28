#include<stdio.h>
#include<vector>
using namespace std;
long pp,mm,color[300],sum,n,t,m,i,a,b;
bool flag;
vector<long>vc[300];
void bcl(long p)
{
	long i;
	for(i=0;i<vc[p].size() && flag;i++)
	{
		if(color[vc[p][i]]==-1)
		{
			color[vc[p][i]]=(color[p]==-1)?1:!color[p];
			if(color[p]==1)
				pp++;
			else
				mm++;
			bcl(vc[p][i]);
		}
		else
			if(color[p]==color[vc[p][i]])
				flag=0;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			color[i]=-1,vc[i].clear();

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&a,&b);
			if(a==b)
				continue;
			vc[a].push_back(b);
			vc[b].push_back(a);
		}

		flag=1;
		sum=0;

		for(i=0;i<n;i++)
			if(vc[i].size()==0)
				sum++;

		for(i=0;i<n && flag;i++)
		{
			mm=0;
			pp=0;
			if(color[i]==-1)
				bcl(i);
			sum+=(mm>pp)?pp:mm;
		}
		if(flag)
			printf("%ld\n",sum);
		else
			printf("-1\n");
	}
	return 0;
}