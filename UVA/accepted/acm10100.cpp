#include<stdio.h>
#include<string.h>

long s[1010][1010],i,j,m,n,sum,cs=1,p;
char st[520][25],sy[520][25],mat[1010][1010],sr[1010],sd[1010];
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
			if(strcmp(st[i-1],sy[j-1])==0)
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
	printf("Length of longest match: %ld\n",sum);
}

int main()
{
	while(gets(sr),gets(sd))
	{
		printf("%2ld. ",cs++);
		if(sr[0]==0 || sd[0]==0)
		{
			printf("Blank!\n");
			continue;
		}
		n=0;
		p=strlen(sr);
		for(i=0;i<p;i++)
		{
			if((sr[i]>64 && sr[i]<91) || (sr[i]>96 && sr[i]<123) || (sr[i]>47 && sr[i]<58))
			{
				j=0;
				while(i<p && (sr[i]>64 && sr[i]<91) || (sr[i]>96 && sr[i]<123) || (sr[i]>47 && sr[i]<58))
					st[n][j++]=sr[i++];
				st[n][j]=0;
				i--;
				n++;
			}
		}

		m=0;
		p=strlen(sd);
		for(i=0;i<p;i++)
		{
			if((sd[i]>64 && sd[i]<91) || (sd[i]>96 && sd[i]<123) || (sd[i]>47 && sd[i]<58))
			{
				j=0;
				while(i<p && (sd[i]>64 && sd[i]<91) || (sd[i]>96 && sd[i]<123) || (sd[i]>47 && sd[i]<58))
					sy[m][j++]=sd[i++];
				sy[m][j]=0;
				i--;
				m++;
			}
		}
		init();
		lcs();
	}
	return 0;
}