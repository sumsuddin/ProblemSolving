#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long i,j,p,cs,la,c;
char ch,st[201],sy[50001][201];

int sorting(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}

int main()
{
	j=0;
	while(~scanf("%c",&ch))
	{
		if(ch>64 && ch<91)
			sy[j][la++]=ch+32;
		else
			if(ch=='-')
			{
				scanf("%c",&ch);
				if(ch=='\n')
					continue;
				sy[j][la++]='-';
				sy[j][la++]=ch;
			}
			else 
				if(ch>96 && ch<123)
					sy[j][la++]=ch;
				else
				{
					sy[j][la]=0;
					la=0;
					j++;
				}

	}
	strcpy(st,"");
	qsort((void *)sy, j, sizeof(sy[0]), sorting);
	for(i=0;i<j;i++)
	{
		if(strcmp(sy[i],st)!=0)
		{
			printf("%s\n",sy[i]);
			strcpy(st,sy[i]);
		}
	}
	return 0;
}