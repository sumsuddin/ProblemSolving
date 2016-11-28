#include <stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n

long sy[300],i,j,max;
char st[1000];

int main()
{
	while(gets(st))
	{
		max=0;
		for(i=0;st[i];i++)
		{
			sy[st[i]]++;
		}
		for(i=65;i<91;i++)
		{
			if(sy[i]>max)
				max=sy[i];
		}

		for(i=97;i<123;i++)
		{
			if(sy[i]>max)
				max=sy[i];
		}
		for(i=65;i<91;i++)
		{
			if(sy[i]==max)
				printf("%c",i);
		}
		for(i=97;i<123;i++)
		{
			if(sy[i]==max)
				printf("%c",i);
		}
	
		printf(" %ld\n",max);
		for(i=97;i<123;i++)
			sy[i]=0;

		for(i=65;i<91;i++)
			sy[i]=0;

	}
	return 0;
}