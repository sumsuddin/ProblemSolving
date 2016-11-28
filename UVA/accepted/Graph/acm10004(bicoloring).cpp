#include<stdio.h>
#include<vector>
using namespace std;
long i,color[500],x,y,n,m,flag;
vector<long>vc[500];
void bcl(long p)
{
	long i;
	for(i=0;i<vc[p].size() && flag;i++)
	{
		if(color[vc[p][i]]==-1)
		{
			color[vc[p][i]]=(color[p]==-1)?1:!color[p];
			bcl(vc[p][i]);
		}
		else
			if(color[p]==color[vc[p][i]])
				flag=0;
	}
}

int main()
{
	while(scanf("%ld",&n),n)
	{
		scanf("%ld",&m);

		while(m--)
		{
			scanf("%ld%ld",&x,&y);
			vc[x].push_back(y);
			vc[y].push_back(x);
		}
		for(i=0;i<n;i++)
			color[i]=-1;
		flag=1;
		for(i=0;i<n;i++)
		{
			if(color[i]==-1)
				bcl(i);
		}
		if(flag)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		for(i=0;i<n;i++)
			vc[i].clear();
	}
	return 0;
}
