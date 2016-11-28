#include<stdio.h>
#include<ctype.h>
int main()
{

	char st[150];
	long int i,word;

	while(gets(st))
	{
		word=0;
		for(i=0;st[i];i++)
		{
			if(isalpha(st[i]))
			{
				for(i;isalpha(st[i]);)
					i++;
				i--;
				word++;
			}
			else
			{
				for(i;!isalpha(st[i]) && st[i];)
					i++;
				i--;
			}
		}
		printf("%ld\n",word);
	}
	return 0;
}