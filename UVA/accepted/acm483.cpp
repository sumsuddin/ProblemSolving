#include<stdio.h>
int main()
{
	char st[1005],sy[105];
	long i,j;
	while(gets(st))
	{
		i=0;
		for(j=0;;j++)
		{
			if(st[i]==' ' || st[i]==0)
			{
				while(j--)
					printf("%c",sy[j]);
				if(st[i]==0)
				{
					printf("\n");
					break;
				}
				else
					printf(" ");
				i++;
			}
			else
				sy[j]=st[i++];
		}
	}
	return 0;
}