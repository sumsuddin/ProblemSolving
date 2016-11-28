#include<stdio.h>
#include<string.h>
void sum(char st[],char sy[],long int *a,long int *b)
{
	int carry=0,s,p,i,t=0;
	if(*a>=*b)
	{
		p=*a;
		for(i=*b;i<*a;i++)
			sy[i]=48;
	}
	else
	{
		p=*b;
		for(i=*a;i<*b;i++)
			st[i]=48;
	}


	for(i=0;i<p;i++)
	{
		s=st[i]+sy[i]+carry-48;
		if(s>57)
		{
			carry=1;
			s-=10;
		}
		else
			carry=0;
		if(s==48)
		{
			if(i==t++)
				continue;
		}

		printf("%c",s);
	}
	if(carry)
		printf("1");
}

int main()
{
	char st[205],sy[205];
	long int n,a,b;

	scanf("%ld",&n);
	while(n--)
	{
		scanf("%s%s",st,sy);

		a=strlen(st);b=strlen(sy);

		sum(st,sy,&a,&b);

		printf("\n");
	}
	return 0;
}
