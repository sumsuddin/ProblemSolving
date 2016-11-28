#include<stdio.h>
#include<string.h>
int main()
{
	long int n;
	char st[25][25];

	strcpy(st[8],"40320");
	strcpy(st[9],"362880");
	strcpy(st[10],"3628800");
	strcpy(st[11],"39916800");
	strcpy(st[12],"479001600");
	strcpy(st[13],"6227020800");


	while(scanf("%ld",&n)==1)
	{
		if(n<0)////From tool kit why don't know!!!!
		{
			if(n%2)
				printf("Overflow!\n");
			else
				printf("Underflow!\n");
		}
		else
		{
			if(n<8)
				printf("Underflow!\n");
			else
			{
				if(n>13)
					printf("Overflow!\n");
				else
					printf("%s\n",st[n]);
			}
		}
	}
	return 0;
}