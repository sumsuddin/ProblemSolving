#include<stdio.h>


int main()
{
	int i;

	char str[10001]; 



	while(gets(str))
	{
		for(i=0;str[i];i++)
		{
			str[i]-=7;
		}


		printf("%s\n",str);
	}


	return 0;
}