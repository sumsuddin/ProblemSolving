#include<stdio.h>
#include<string.h>
int main()
{
	long int n,l,i,j,p;
	char st[105],xx[110];
	while(gets(xx))
	{
		sscanf(xx,"%ld%s",&n,st);
		if(!n)
			break;
		p=0;
		l=strlen(st)/n;


		for(i=1;i<=n;i++)
		{
			for(j=l*i-1;j>=p;j--)
				printf("%c",st[j]);
			p=l*i;
		}
		printf("\n");
	}return 0;
}