#include<stdio.h>
#include<string.h>
long n,a,sum,l;
char c[1000010];

int main()
{
	while(scanf("%s",c) && c[0]!='E')
	{
		if(strcmp(c,"1")==0)
			printf("1\n");
		else
		{
			l=strlen(c);
			a=l;
			sum=1;
			while(a!=1)
			{
				l=a;
				a=0;
				while(l)
				{
					a++;
					l/=10;
				}
				sum++;
			}
			printf("%ld\n",sum+1);
		}
	}
	return 0;
}