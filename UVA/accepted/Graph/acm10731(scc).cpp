#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct sss
{
	long fin,ind;
}sr[550];
vector<long>vc[100];
vector<long>vt[100];
long i,j,prin[100][100],n,tim,len[100],mn;
bool vst[100],vsit[100],flag;
char a[10],b[10],c[10],d[10],e[10],ans[10];
void dfs(long a)
{
	long k;
	for(k=0;k<vc[a].size();k++)
		if(vst[vc[a][k]])
		{
			tim++;
			vst[vc[a][k]]=0;
			dfs(vc[a][k]);
		}
	sr[a].fin=++tim;
}

void dfs1(long a)
{
	long k;
	for(k=0;k<vt[a].size();k++)
	{
		if(vst[vt[a][k]])
		{
			prin[tim][len[tim]++]=vt[a][k];
			vst[vt[a][k]]=0,dfs1(vt[a][k]);
		}
	}
}

bool cmpr(sss a,sss b)
{
	if(a.fin>b.fin)
		return 1;
	else
		return 0;
}

int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%s%s%s%s%s",a,b,c,d,e,ans);

			vc[ans[0]-'A'].push_back(a[0]-'A');
			vc[ans[0]-'A'].push_back(b[0]-'A');
			vc[ans[0]-'A'].push_back(c[0]-'A');
			vc[ans[0]-'A'].push_back(d[0]-'A');
			vc[ans[0]-'A'].push_back(e[0]-'A');

			vt[a[0]-'A'].push_back(ans[0]-'A');
			vt[b[0]-'A'].push_back(ans[0]-'A');
			vt[c[0]-'A'].push_back(ans[0]-'A');
			vt[d[0]-'A'].push_back(ans[0]-'A');
			vt[e[0]-'A'].push_back(ans[0]-'A');


			vst[a[0]-'A']=1,vst[b[0]-'A']=1,vst[c[0]-'A']=1,vst[d[0]-'A']=1,vst[e[0]-'A']=1,vst[ans[0]-'A']=1;
		}
		if(flag)
			printf("\n");
		else
			flag=1;
		for(i=0;i<26;i++)
			vsit[i]=vst[i],sr[i].fin=0;

		tim=0;
		for(i=0;i<26;i++)
			if(vst[i])
				vst[i]=0,dfs(i);

		for(i=0;i<26;i++)
			vst[i]=vsit[i],sr[i].ind=i;

		sort(sr,sr+26,cmpr);

		tim=0;
		for(i=0;i<26;i++)
		{
			if(vst[sr[i].ind])
			{
				prin[tim][0]=sr[i].ind;
				len[tim]=1;
				vst[sr[i].ind]=0;
				dfs1(sr[i].ind);
				tim++;
			}
		}
		for(i=0;i<tim;i++)
			sort(prin[i],prin[i]+len[i]);
		n=0;
		for(i=0;i<tim;i++)
		{
			mn=100000;
			for(j=0;j<tim;j++)
				if(mn>prin[j][0])
				{
					mn=prin[j][0];
					n=j;
				}
			
			printf("%c",prin[n][0]+'A');
			prin[n][0]=100001;
			for(j=1;j<len[n];j++)
				printf(" %c",prin[n][j]+'A');
			printf("\n");
		}
		for(i=0;i<26;i++)
			vc[i].clear(),vt[i].clear();
	}
	return 0;
}