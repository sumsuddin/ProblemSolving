#include<stdio.h>
#include<string.h>

long division(char a[])
{
	long i,ex;
	for(i=0,ex=0;a[i];i++)
	{
		ex=ex*10+(a[i]-48);
		ex=ex%17;
	}
	return ex;
}

int main()
{
	char st[500];
	long ex;
	while(gets(st),st[0]-48)
	{
		ex=division(st);
        if(!ex)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
