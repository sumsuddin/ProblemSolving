#include<stdio.h>
#include<string.h>

long i,ex;
bool L,P,po=0;;
char st[10000000];

long div(char a[],long b)
{

	for(i=0,ex=0;a[i];i++)
	{
		ex=ex*10+(a[i]-48);
		ex=ex%b;
	}
	return ex;
}

int main()

{

	while(gets(st))
	{
		if(po)
			printf("\n");
		else
			po=1;

		P=1;L=0;
		if(!div(st,4))
		{
			if(!div(st,100))
			{
				if(!div(st,400))
					L=1;
			}
			else
				L=1;
		}
		if(L)
		{
			printf("This is leap year.\n");
			P=0;
		}

		if(!div(st,15))
		{
			printf("This is huluculu festival year.\n");
			P=0;
		}

		if(L && !div(st,55))
		{
			printf("This is bulukulu festival year.\n");
			P=0;
		}

		if(P)
			printf("This is an ordinary year.\n");
	}
	return 0;
}