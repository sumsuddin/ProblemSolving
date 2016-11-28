#include<stdio.h>
char st[150][150];
long i,j,k,l,n,m,c,p=1;
int main()
{
	while(scanf("%ld%ld",&m,&n) && (m||n))
	{
		for(i=0;i<m;i++)
			scanf("%s",&st[i]);
		if(p!=1)
			printf("\nField #%ld:\n",p++);
		else
			printf("Field #%ld:\n",p++);

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(st[i][j]=='.')
				{
					c=0;
					for(k=i-1;k<=i+1;k++)
					{
						for(l=j-1;l<=j+1;l++)
						{
							if(k>=0 && l>=0 && k<m && l<n)
								if(st[k][l]=='*')
									c++;
						}
					}
					printf("%ld",c);

				}
				else
					printf("%c",st[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}