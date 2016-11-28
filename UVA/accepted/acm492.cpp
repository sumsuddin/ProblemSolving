#include<stdio.h>
int main()
{
	char st[1000005],c;
	long i;
	while(gets(st))
	{
		for(i=0;st[i];i++)
		{
			if(st[i]=='a' || st[i]=='e' || st[i]=='i' || st[i]=='o' || st[i]=='u' || st[i]=='A' || st[i]=='E' || st[i]=='I' || st[i]=='O' || st[i]=='U')
			{
				for(i;(st[i]>64 && st[i]<91) || (st[i]>96 && st[i]<123);i++)
					printf("%c",st[i]);
				printf("ay");
			}
			else
				if((st[i]>64 && st[i]<91) || (st[i]>96 && st[i]<123))
				{
					c=st[i++];
					for(i;(st[i]>64 && st[i]<91) || (st[i]>96 && st[i]<123);i++)
						printf("%c",st[i]);
					printf("%cay",c);
				}
				if(st[i])
					printf("%c",st[i]);
				else
					break;
		}
		printf("\n");
	}
	return 0;
}
