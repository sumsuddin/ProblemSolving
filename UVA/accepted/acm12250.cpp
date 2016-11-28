#include<stdio.h>
#include<string.h>
char st[20];
long cs=1;
int main()
{
	while(~scanf("%s",st) && strcmp(st,"#"))
	{
		printf("Case %ld: ",cs++);
		if(strcmp(st,"HELLO")==0)
			printf("ENGLISH\n");
		else
			if(strcmp(st,"HOLA")==0)
				printf("SPANISH\n");
		else
			if(strcmp(st,"HALLO")==0)
				printf("GERMAN\n");
		else
			if(strcmp(st,"CIAO")==0)
				printf("ITALIAN\n");
		else
			if(strcmp(st,"BONJOUR")==0)
				printf("FRENCH\n");
		else
			if(strcmp(st,"ZDRAVSTVUJTE")==0)
				printf("RUSSIAN\n");
		else
			printf("UNKNOWN\n");
	}
	return 0;
}