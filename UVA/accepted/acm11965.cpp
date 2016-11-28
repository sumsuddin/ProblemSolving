#include<stdio.h>
long i,n,m,p=1;
char b,c;
int main()
{
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		scanf("%ld",&m);
		getchar();
		printf("Case %ld:\n",p++);
		while(m--)
		{
			b=1;
			while(1)
			{
				c=getchar();
				if(c=='\n')
					break;
				else
					if(b==' ' && c==' ')
						continue;
					else
						printf("%c",c);
				b=c;
			}
			printf("\n");
		}
		if(n)
			printf("\n");
	}
	return 0;
}