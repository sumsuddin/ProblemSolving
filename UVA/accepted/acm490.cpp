#include<stdio.h>
#include<string.h>
int main()
{
	char st[150][150];
	int i=0,j,k,l=0,max,len[150];

	while(gets(st[i]))
		i++;

	k=i-1;

	max=0;
	while(i--)
	{
		len[i]=strlen(st[i]);
		if(max<len[i])
			max=len[i];
	}

	for(j=0;j<max;j++)
	{
		for(i=k;i>=0;i--)
		{
			if(st[i][j]<=0)
				st[i][j]=' ';
			printf("%c",st[i][j]);
		}
		printf("\n");
	}
	return 0;
}
