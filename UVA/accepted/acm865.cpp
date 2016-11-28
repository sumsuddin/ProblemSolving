#include<stdio.h>

long i,n;
char st[500],sy[500],rep[500];
bool flag;

int main()
{
	gets(st);
	sscanf(st,"%ld",&n);
	flag=0;

	while(gets(st))
	{
		if(st[0]==0)
		{
			n--;
			if(n<0)
				break;
			else
			{
				for(i=0;i<300;i++)
					rep[i]=0;
				if(flag)
					printf("\n");
				else
					flag=1;

				gets(st);
				gets(sy);
				for(i=0;st[i];i++)
				{
					rep[st[i]]=sy[i];
				}
				puts(sy);
				puts(st);
			}
		}
		else
		{
			for(i=0;st[i];i++)
				if(rep[st[i]])
					printf("%c",rep[st[i]]);
				else
					printf("%c",st[i]);
			printf("\n");
		}
	}
	return 0;
}