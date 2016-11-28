#include<stdio.h>
#include<string.h>
#define MAX 110
long st[MAX],sy[MAX],s[MAX][MAX],i,j,m,n,sum,cs=1;
char mat[MAX][MAX];
void init()
{
	sum=0;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			s[i][j]=0,mat[i][j]=0;
}
void dfs(long a,long b)
{
	if(a==0 || b==0)
		return;
	if(mat[a][b]=='c')
	{
		dfs(a-1,b-1);
		sum++;	
	}
	else
		if(mat[a][b]=='u')
			dfs(a-1,b);
		else
			dfs(a,b-1);
}
void lcs()
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(st[i-1]==sy[j-1])
			{
				s[i][j]=s[i-1][j-1]+1;
				mat[i][j]='c';
			}
			else
				if(s[i-1][j]>s[i][j-1])
				{
					s[i][j]=s[i-1][j];
					mat[i][j]='u';
				}	
				else
				{
					s[i][j]=s[i][j-1];
					mat[i][j]='l';
				}
		}
	}
	dfs(n,m);
	printf("Twin Towers #%ld\nNumber of Tiles : %ld\n\n",cs++,sum);
}

int main()
{
	while(scanf("%ld%ld",&n,&m) && (m||n))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);
		for(i=0;i<m;i++)
			scanf("%ld",&sy[i]);
		init();
		lcs();
	}
	return 0;
}