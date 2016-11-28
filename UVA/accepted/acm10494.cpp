#include<stdio.h>
#include<string.h>
	char sy[100000],c;
long division(char a[],long *b)
{
	long i,ex;
	for(i=0,ex=0;a[i];i++)
	{
		ex=ex*10+(a[i]-48);
		a[i]=ex/ *b+'0';
		ex=ex%*b;
	}
	return ex;
}

int main()
{
	long div,ex,i;
	while(scanf("%s %c %ld",sy,&c,&div)==3)
	{
		ex=division(sy,&div);
		for(i=0;sy[i]=='0';i++);
		for(div=0;sy[i];i++,div++)
            sy[div]=sy[i];
		sy[div]=0;
		if(sy[0]==0)
		{
			sy[0]='0';
			sy[1]=0;
		}
		if(c=='/')
			puts(sy);
		else
			printf("%ld\n",ex);
	}
	return 0;
}
