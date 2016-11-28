#include<stdio.h>
#include<string.h>
int main()
{
	char st[1005],sy[1005];
	long i,j,d;
	while(gets(st))
	{
		j=0;
		if(!strcmp(st,"DONE"))
			break;
		for(i=0;st[i];i++)
		{
			if(st[i]>96 && st[i]<123)
				sy[j++]=st[i]-32;
			else
				if(st[i]>64 &&st[i]<91)
					sy[j++]=st[i];
		}
		sy[j]=0;
		d=1;
		for(i=0;sy[i];i++)
		{
			if(sy[i]!=sy[--j])
			{
				printf("Uh oh..\n");
				d=0;
				break;
			}
		}
		if(d)
			printf("You won't be eaten!\n");
	}
	return 0;
}
