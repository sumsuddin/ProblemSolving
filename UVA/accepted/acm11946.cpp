#include<stdio.h>
char s[200];
long i,n;
int main()
{
	gets(s);
	sscanf(s,"%ld",&n);

	while(n--)
	{
		while(gets(s))
		{
			if(s[0]==0)
				break;
			for(i=0;s[i];i++)
			{
				if(s[i]<'0' || s[i]>'9')
					printf("%c",s[i]);
				else
				{
					switch (s[i])
					{
					case '0':
						printf("O");
						break;
					case '1':
						printf("I");
						break;
					case '2':	
						printf("Z");
						break;
					case '3':	
						printf("E");
						break;
					case '4':
						printf("A");
						break;
					case '5':	
						printf("S");
						break;
					case '6':
						printf("G");
						break;
					case '7':
						printf("T");
						break;
					case '8':
						printf("B");
						break;
					case '9':
						printf("P");
					}
				}
			}
			printf("\n");
		}
		if(n)
			printf("\n");
	}
	return 0;
}
