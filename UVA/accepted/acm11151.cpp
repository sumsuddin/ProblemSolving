#include<stdio.h>
#include<string.h>
#define MAX 1005
long s[MAX][MAX],i,j,n,m,sum;
char st[MAX],sy[MAX],mat[MAX][MAX];
void init()
{
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
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
		for(j=1;j<=n;j++)
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
	dfs(n,n);
}

int main()
{
	gets(st);
	sscanf(st,"%ld",&m);
	while(m--)
	{
		gets(st);
		n=strlen(st);
		for(i=n-1,j=0;j<n;j++,i--)
			sy[j]=st[i];
		sy[j]=0;
		sum=0;
		init();
		lcs();
		printf("%ld\n",sum);
	}
	return 0;
}