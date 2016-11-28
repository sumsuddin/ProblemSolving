#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long t,lst,mat[110][110],path[110][110],k;
char st[110],sy[110],ss[110];
struct ssss
{
	char s[110];
}
str[10100];

void lcs()
{
	long i,j;
	for(i=0;st[i];i++)
	{
		for(j=0;sy[j];j++)
		{
			if(st[i]==sy[j])
				mat[i+1][j+1]=mat[i][j]+1,path[i+1][j+1]=1;
			else if(path[i][j+1]>path[i+1][j])
				mat[i+1][j+1]=mat[i][j+1],path[i+1][j+1]=2;
			else
				mat[i+1][j+1]=mat[i+1][j],path[i+1][j+1]=3;
		}
	}
}

bool cmp(ssss a , ssss b)
{
	if(strlen(a.s)>strlen(b.s) || (strlen(a.s)==strlen(b.s) && strcmp(a.s,b.s)>0))
		return 0;
	else
		return 1;
}
void dfs(long i,long j,long l)
{
	if(i-1>=0 && j-1>=0 && path[i][j]==1)
	{
		ss[l++]=st[i-1];
		if(mat[i][j]==1)
		{
			for(k=l;k>=0;k--)
				str[lst].s[k]=ss[k];
			str[lst].s[l+1]=0;
			lst++;
		}
		else
			dfs(i-1,j-1,l+1);
	}
	if(i-1>=0 && j-1>=0 && mat[i-1][j]==mat[i][j])
		dfs(i-1,j,l);
	if(i-1>=0 && j-1>=0 && mat[i][j-1]==mat[i][j])
		dfs(i,j-1,l);
}


int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s%s",st,sy);

		lcs();

		lst=0;

		dfs(strlen(st),strlen(sy),0);
		sort(str,str+lst,cmp);
		printf("%s\n",str[0].s);
	}
	return 0;
}