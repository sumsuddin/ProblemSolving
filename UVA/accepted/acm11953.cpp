#include<stdio.h>
long i,j,sum,d,t,n,cs=1;
char st[120][120];
int main()
{
	gets(st[0]);
	sscanf(st[0],"%ld",&t);

	while(t--)
	{
		gets(st[0]);
		sscanf(st[0],"%ld",&n);

		for(i=0;i<n;i++)
			gets(st[i]);
		sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;st[i][j];j++)
			{
				if(st[i][j]=='x')
				{
					sum++;
					if(st[i][j+1]=='x' || st[i][j+1]=='@')
					{
						while(st[i][j+1]=='x' || st[i][j+1]=='@')
							st[i][j++]='0';
					}
					else
					{
						d=i;
						while(st[d][j]=='x' || st[d][j]=='@')
							st[d++][j]='0';
					}
				}
			}
		}
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}