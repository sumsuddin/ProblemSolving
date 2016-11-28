#include<stdio.h>
char st[50],sy[50][50],sr[50][50];
long i,j,k,n,t,sum,h[]={-1,-1,-1,0,0,0,1,1,1},v[]={-1,0,1,-1,0,1,-1,0,1};
bool flag;
int main()
{
	gets(st);
	sscanf(st,"%ld",&t);

	while(t--)
	{
		getchar();
		flag=0;

		gets(st);
		sscanf(st,"%ld",&n);

		for(i=0;i<n;i++)
			gets(sy[i]);
		for(j=0;j<=n;j++)
			sy[i][j]=0;
		for(i=0;i<n;i++)
			gets(sr[i]);
		for(j=0;j<=n;j++)
			sr[i][j]=0;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(sr[i][j]=='x')
				{
					if(sy[i][j]=='*')
						flag=1;
					else
					{
						sum=0;
						for(k=0;k<9;k++)
							if(sy[i+h[k]][j+v[k]]=='*')
								sum++;
						sr[i][j]=sum+'0';
					}
				}
			}
		}
		if(flag)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(sy[i][j]=='*')
						printf("*");
					else
						printf("%c",sr[i][j]);
				}
				printf("\n");
			}
		}
		else
			for(i=0;i<n;i++)
				puts(sr[i]);
		if(t)
			printf("\n");
	}
	return 0;
}