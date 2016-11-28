#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<long>vc[70005],wt[70005];
long i,p,q,w,mm,mx,mmx;
bool vst[10050];
char st[100];

void dfs(long sc,long dis)
{
	long i;
	if(dis>mmx)
		mmx=dis,mm=sc;
	for(i=0;i<vc[sc].size();i++)
	{
		w=vc[sc][i];
		if(vst[vc[sc][i]])
		{
			vst[vc[sc][i]]=0;
			dfs(vc[sc][i],dis+wt[sc][i]);
		}
	}
}

int main()
{
	while(gets(st))
	{
		mx=0;
		if(st[0]==0)
		{
			printf("0\n");
			continue;
		}
		sscanf(st,"%ld%ld%ld",&p,&q,&w);
		vc[p].push_back(q);
		wt[p].push_back(w);
		vc[q].push_back(p);
		wt[q].push_back(w);
		if(p>mx)
			mx=p;
		if(q>mx)
			mx=q;

		while(gets(st) && st[0])
		{
			sscanf(st,"%ld%ld%ld",&p,&q,&w);
			vc[p].push_back(q);
			wt[p].push_back(w);
			vc[q].push_back(p);
			wt[q].push_back(w);
			if(p>mx)
				mx=p;
			if(q>mx)
				mx=q;
		}
		for(i=0;i<=mx;i++)
			vst[i]=1;
		mmx=0;
		vst[1]=0;
		mm=1;
		dfs(1,0);

		for(i=0;i<=mx;i++)
			vst[i]=1;

		vst[mm]=0;
		dfs(mm,0);
		printf("%ld\n",mmx);

		for(i=0;i<=mx;i++)
			vc[i].clear(),wt[i].clear();
	}

    return 0;
}
