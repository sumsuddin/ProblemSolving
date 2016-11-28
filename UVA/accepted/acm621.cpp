#include<stdio.h>
#include<string.h>

char sy[1005];
int la,n;

int main()
{
	gets(sy);
	sscanf(sy,"%ld",&n);

	while(n--)
	{
		gets(sy);
		la=strlen(sy);

		if(!strcmp("78",sy) || !strcmp("4",sy) || !strcmp("1",sy))
			printf("+\n");
		else
		{
			if(sy[la-1]=='5' && sy[la-2]=='3')
				printf("-\n");
			else
			{
				if(sy[0]=='9' && sy[la-1]=='4')
					printf("*\n");
				else
				{
					if(sy[0]=='1' && sy[1]=='9' && sy[2]=='0')
						printf("?\n");
				}
			}
		}
	}
	return 0;
}