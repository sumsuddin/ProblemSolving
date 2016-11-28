#include<stdio.h>
long st[20][20],i,j,n,m,p,cs=1;
char a[20][20];
bool flag=0;
int main()
{
	for(i=0;i<15;i++)
	{
		a[i][0]='*';
		a[0][i]='*';
	}

	while(scanf("%ld",&n),n)
	{
		scanf("%ld",&m);
		getchar();

		if(flag)
			printf("\n");
		else
			flag=1;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",&a[i][j]);
				st[i][j]=0;
			}
			getchar();
		}
		p=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j-1]=='*' && a[i][j]!='*')
					st[i][j]=p++;
				else
					if(a[i-1][j]=='*' && a[i][j]!='*')
						st[i][j]=p++;
			}
		}
		printf("puzzle #%ld:\nAcross\n",cs++);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(a[i][j-1]=='*' && st[i][j])
				{
					printf("%3ld.",st[i][j]);
					while(j<=m && a[i][j]!='*')
						printf("%c",a[i][j++]);
					printf("\n");
				}
			}

		printf("Down\n");
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(a[i-1][j]=='*' && st[i][j])
				{
					p=0;
					printf("%3ld.",st[i][j]);
					while(i+p<=n && a[i+p][j]!='*')
						printf("%c",a[i+p++][j]);
					printf("\n");
				}
			}
	}
	return 0;
}