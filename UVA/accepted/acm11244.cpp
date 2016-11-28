#include<stdio.h>
char st[150][150];
bool flag;
long i,j,k,l,n,m,c;
int main()
{
	while(scanf("%ld%ld",&m,&n) && (m||n))
	{
		for(i=0;i<m;i++)
			scanf("%s",&st[i]);

		c=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(st[i][j]=='*')
				{
					flag=1;
					for(k=i-1;k<=i+1;k++)
					{
						for(l=j-1;l<=j+1;l++)
						{
							if(k>=0 && l>=0 && k<m && l<n && (k!=i || l!=j))
								if(st[k][l]=='*')
									flag=0;
						}
					}
					if(flag)
						c++;
				}
			}
		}
		printf("%ld\n",c);
	}
	return 0;
}