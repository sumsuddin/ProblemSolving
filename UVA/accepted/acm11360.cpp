#include<stdio.h>
#include<string.h>
void swap(char *a,char*b)
{
	char c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	char st[15][15],sy[10],su[5];
	int a,b,i,j,n,t,m,k=1;
		gets(su);
		sscanf(su,"%d",&t);
	while(t--)
	{
		gets(su);
		sscanf(su,"%d",&n);

		for(i=0;i<n;i++)
			gets(st[i]);


		gets(su);
		sscanf(su,"%d",&m);
		while(m--)
		{
			gets(sy);

			if(sy[0]=='r')
			{
				sscanf(sy,"%*s%d%d",&a,&b);
				a--;b--;
				for(i=0;i<n;i++)
					swap(&st[a][i],&st[b][i]);
			}
			if(sy[0]=='c')
			{
				sscanf(sy,"%*s%d%d",&a,&b);
				a--;b--;
				for(i=0;i<n;i++)
					swap(&st[i][a],&st[i][b]);
			}
			if(!strcmp(sy,"inc"))
			{
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
					{
						if(st[i][j]=='9')
							st[i][j]='0';
						else
							st[i][j]++;
					}

			}
			if(!strcmp(sy,"dec"))
			{
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
					{
						if(st[i][j]=='0')
							st[i][j]='9';
						else
							st[i][j]--;
					}

			}
			if(sy[0]=='t')
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<i;j++)
						swap(&st[i][j],&st[j][i]);
				}
			}
		}
		printf("Case #%d\n",k++);
		for(i=0;i<n;i++)
			puts(st[i]);
		printf("\n");
	}
	return 0;
}
