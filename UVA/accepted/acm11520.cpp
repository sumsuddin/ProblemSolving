#include<stdio.h>
long cs=1,i,j,k,t,n;
char st[20][20];
int main()
{
	gets(st[1]);
	sscanf(st[1],"%ld",&t);

	while(t--)
	{
		gets(st[1]);
		sscanf(st[1],"%ld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%c",&st[i][j]);
			getchar();
		}

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(st[i][j]=='.')
				{
					for(k=65;k<91;k++)
						if(st[i][j+1]!=k && st[i][j-1]!=k && st[i-1][j]!=k && st[i+1][j]!=k)
						{
							st[i][j]=(char)k;
							break;
						}
				}
			}
		printf("Case %ld:\n",cs++);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c",st[i][j]);
			printf("\n");
		}
	}
	return 0;
}