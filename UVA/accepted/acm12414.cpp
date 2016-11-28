#include<stdio.h>
#include<string.h>
long i,ls,p;
char st[100],sy[1000];
bool flag;

void rev(char st[],long l)
{
	long i,j;
	for(i=0,j=l-1;i<l/2;i++,j--)
		st[i]^=st[j]^=st[i]^=st[j];
}

bool summ()
{
	long i;
	while(ls>2)
	{
		for(i=1;sy[i];i++)
			sy[i-1]=(sy[i-1]-'0'+sy[i]-'0')%10+'0';
		sy[--ls]=0;
		if(strcmp(sy,"100")==0)
			return 1;
	}
	return 0;
}

bool yun(long a)
{
	long i;
	ls=0;
	for(i=0;st[i];i++)
	{
		p=st[i]-'A'+a;
		while(p)
			sy[ls++]=p%10+'0',p/=10;
	}
	rev(sy,ls);
	if(summ())
		return 1;
	else
		return 0;
}

int main()
{
	while(gets(st))
	{
		rev(st,strlen(st));
		flag=1;
		for(i=81;i<=10000;i++)
		{
			if(yun(i))
			{
				printf("%ld\n",i);
				flag=0;
				break;
			}
		}
		if(flag)
			printf(":(\n");
	}
	return 0;
}
