#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long i,j,p,cs,la,c;
char st[201],sy[50001][201];

int sorting(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}

int main()
{
	j=0;
	while(~scanf("%s",sy[j]))
	{
		la=0;
		c=0;
		for(i=0;sy[j-c][i];i++)
			if(sy[j-c][i]>64 && sy[j-c][i]<91)
				sy[j][la++]=sy[j-c][i]+32;
			else
				if(sy[j-c][i]>96 && sy[j-c][i]<123)
					sy[j][la++]=sy[j-c][i];
				else
				{
					sy[j][la]=0;
					j++;
					la=0;
					c++;
				}


		sy[j][la]=0;
		j++;
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