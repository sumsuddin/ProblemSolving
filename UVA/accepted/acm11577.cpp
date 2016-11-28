#include<stdio.h>
int main()
{
	char st[250];

	long sy[30],i,max,n;

	for(i=0;i<27;i++)
		sy[i]=0;

	gets(st);
	sscanf(st,"%ld",&n);

	while(n--)
	{
		gets(st);

		for(i=0;st[i];i++)
		{
			if(st[i]>64 && st[i]<91)
				sy[st[i]-65]++;
			else
				if(st[i]>96 && st[i]<123)
					sy[st[i]-97]++;
		}
		max=0;
		for(i=0;i<27;i++)
		{
			if(sy[i]>max)
				max=sy[i];
		}
		for(i=0;i<27;i++)
		{
			if(sy[i]==max)
				printf("%c",i+97);
			sy[i]=0;
		}
		printf("\n");
	}
	return 0;
}