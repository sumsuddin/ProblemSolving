#include<stdio.h>
int main()
{
	long n[25],i;
	char ch;
	bool flag,prin;


	while(scanf("%ld",&n[0])==1)
	{
			flag =0;prin=1;
		for(i=1;i<9;i++)
			scanf("%ld",&n[i]);
		for(i=0;i<7;i++)
		{
			if(n[i])
			{
				if(n[i]<0)
				{
					ch='-';
					n[i]*=-1;
				}
				else
					ch='+';
				if(flag)
					printf(" %c ",ch);
				else
				{
					if(ch=='-')
						printf("%c",ch);
					flag=1;
				}
				if(n[i]==1)
					printf("x^%ld",8-i);
				else
					printf("%ldx^%ld",n[i],8-i);
				prin=0;
		
			}
		}
		if(n[i])
		{
			if(n[i]<0)
			{
				ch='-';
				n[i]*=-1;
			}
			else
				ch='+';
			if(flag)
				printf(" %c ",ch);
			else
			{
				if(ch=='-')
					printf("%c",ch);
				flag=1;
			}

			if(n[i]==1)
				printf("x");
			else
				printf("%ldx",n[i]);
			prin=0;
		}

		if(n[++i])
		{
			if(n[i]<0)
			{
				ch='-';
				n[i]*=-1;
			}
			else
				ch='+';
			if(flag)
				printf(" %c ",ch);
			else
			{
				if(ch=='-')
					printf("%c",ch);
				flag=1;
			}

			printf("%ld",n[i]);
			prin=0;
		}
		if(prin)
			printf("0\n");
		else
			printf("\n");
	}
	return 0;
}