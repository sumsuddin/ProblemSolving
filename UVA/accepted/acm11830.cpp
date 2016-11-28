#include<stdio.h>
#include<string.h>
int main()
{
	char st[150];
	int d,i;

	while(gets(st))
	{
		if(!strcmp(st,"0 0"))
			break;
		d=1;

		for(i=2;st[i];i++)
		{
				if(st[i]!=st[0] && st[i]!='0')
				{
					d=0;
					printf("%c",st[i]);
				}
		}
		if(d)
			printf("0\n");
		else
			printf("\n");
	}
	return 0;
}