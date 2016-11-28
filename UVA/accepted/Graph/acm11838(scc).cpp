#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[1050];
vector<long>vt[1050];
long mx,time,n,eg,p,q,i,fin[1050],dir;
bool vst[1050];
void dfs(long a)
{
	long k;
	for(k=0;k<vc[a].size();k++)
		if(vst[vc[a][k]])
		{
			time++;
			vst[vc[a][k]]=0;
			dfs(vc[a][k]);
		}
	fin[a]=++time;
}

void dfs1(long a)
{
	long k;
	for(k=0;k<vt[a].size();k++)
	{
		if(vst[vt[a][k]])
			time=time+1,vst[vt[a][k]]=0,dfs1(vt[a][k]);
	}
}

int main()
{
	while(~scanf("%ld%ld",&n,&eg) && (n || eg))
	{
		mx=0;
		for(i=1;i<=n;i++)
			fin[i]=0,vst[i]=1;

		for(i=0;i<eg;i++)
		{
			scanf("%ld%ld%ld",&p,&q,&dir);
			if(dir==1)
			{
				vc[p].push_back(q);
				vt[q].push_back(p);
			}
			else
			{
				vc[p].push_back(q);
				vc[q].push_back(p);

				vt[p].push_back(q);
				vt[q].push_back(p);
			}
		}
		time=0;
		for(i=1;i<=n;i++)
			if(vst[i])
				vst[i]=0,dfs(i);
		for(i=1;i<=n;i++)
		{
			vst[i]=1;
			mx=(fin[i]>fin[mx])?i:mx;
		}

		time=1;
		vst[mx]=0;
		dfs1(mx);

		if(time==n)
			printf("1\n");
		else
			printf("0\n");
		for(i=0;i<=n;i++)
		{
			vc[i].clear();
			vt[i].clear();
		}
	}
	return 0;
}
