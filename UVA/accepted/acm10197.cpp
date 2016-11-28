#include<stdio.h>
#include<string.h>
bool flag=0;
long la;
char st[100],sy[100];
int main()
{
	while(gets(sy))
	{
		sscanf(sy,"%s%s",st,sy);
		if(flag)
			printf("\n");
		else
			flag=1;

		la=strlen(st);
		printf("%s (to %s)\n",st,sy);

		if(st[la-2]=='a' && st[la-1]=='r')
		{
			st[la-2]=0;
			printf("eu        %so\ntu        %sas\nele/ela   %sa\nnós       %samos\nvós       %sais\neles/elas %sam\n",st,st,st,st,st,st);
		}
		else if(st[la-2]=='e' && st[la-1]=='r')
		{
			st[la-2]=0;
			printf("eu        %so\ntu        %ses\nele/ela   %se\nnós       %semos\nvós       %seis\neles/elas %sem\n",st,st,st,st,st,st);
		}
		else if(st[la-2]=='i' && st[la-1]=='r')
		{
			st[la-2]=0;
			printf("eu        %so\ntu        %ses\nele/ela   %se\nnós       %simos\nvós       %sis\neles/elas %sem\n",st,st,st,st,st,st);
		}
		else
			printf("Unknown conjugation\n");
	}
	return 0;
}