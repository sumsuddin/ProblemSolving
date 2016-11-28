#include<stdio.h>
#include<string.h>
long i,d,sy[5];
char st[500];
bool flag;

int main()
{
	while(gets(st))
	{
		if(!strcmp(st,"e/o/i"))
			break;

		d=0;flag=0;sy[0]=sy[1]=sy[2]=0;
		for(i=0;st[i];i++)
		{
			if(st[i]=='/')
			{
				flag=0;
				d++;
			}
			else
				if(st[i]=='a' || st[i]=='e' || st[i]=='i' || st[i]=='o' || st[i]=='u' || st[i]=='y')
				{
					if(flag==0)
						sy[d]++;
					flag=1;
				}
				else
					flag=0;
		}
		if(sy[0]!=5)
			printf("1\n");
		else
		{
			if(sy[1]!=7)
				printf("2\n");
			else
			{
				if(sy[2]!=5)
					printf("3\n");
				else
					printf("Y\n");
			}
		}
	}
	return 0;
}