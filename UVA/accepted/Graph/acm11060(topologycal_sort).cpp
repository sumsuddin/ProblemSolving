#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;
map<string,long>mp;
vector<long>vc[250],vpr[250];
queue<long>que;
bool vst[250],tru;
long i,j,indeg[250],n,m,print,cs=1;
char st[250],sy[250],sr[250][250];
void topsort()
{
	for(i=1;i<=n;i++)
		vst[i]=1;
	tru=1;
	while(tru)
	{
		tru=0;
		for(i=1;i<=n;i++)
			if(vst[i] && indeg[i]==0)
			{
				printf(" %s",sr[i]);
				vst[i]=0;
				print=i;
				tru=1;
				break;
			}
		for(i=0;i<vc[print].size();i++)
		{
			if(indeg[vc[print][i]])
				indeg[vc[print][i]]--;
		}
	}
}

int main()
{
	while(~scanf("%ld",&n))
	{
		indeg[0]=0;
		for(i=1;i<=n;i++)
		{
			indeg[i]=0;
			scanf("%s",sr[i]);

			mp[sr[i]]=i;
		}
		
		scanf("%ld",&m);

		while(m--)
		{
			scanf("%s%s",st,sy);

			vc[mp[st]].push_back(mp[sy]);

			indeg[mp[sy]]++;
		}
		printf("Case #%ld: Dilbert should drink beverages in this order:",cs++);

		topsort();
		printf(".\n\n");
		for(i=0;i<=n;i++)
			vc[i].clear(),vpr[i].clear();
	}
	return 0;
}
