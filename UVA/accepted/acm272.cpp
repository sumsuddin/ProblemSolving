#include<stdio.h>
int main()
{
	char c,d=1;;

	while(scanf("%c",&c)!=EOF)
	{

		if(c=='"')
		{
			if(d%2)
				printf("``");
			else
				printf("''");
			d++;
		}
		else
			printf("%c",c);
	}
	return 0;
}