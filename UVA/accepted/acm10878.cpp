#include<stdio.h>
#include<math.h>
int sum,sy[30],i,j;
char st[30];
int main()
{
	gets(st);
	while(gets(st) && st[0]!='_')
	{
		j=7;
		for(i=1;i<10;i++)
		{
			if(st[i]==' ')
				sy[j--]=0;
			else
				if(st[i]=='o')
					sy[j--]=1;
		}
		sum=0;
		for(i=0;i<8;i++)
			sum+=(sy[i]*(int)pow(2,i));
		printf("%c",sum);
	}
	return 0;
}

