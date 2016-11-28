#include<stdio.h>
#include<string.h>
#include<math.h>
long sum,l,i;
char st[1050];
int main()
{
	while(~scanf("%s",st) && st[0]!='0')
	{
		l=strlen(st);
		if(l%2==0)
		{
			sum=(st[1]-'0')+((st[0]-'0')*10);
			printf("%ld",(long)sqrt(sum));
			l/=2;
			for(i=1;i<l;i++)
				printf("0");
		}
		else
		{
			printf("%ld",(long)sqrt(st[0]-'0'));
			l/=2;

			for(i=0;i<l;i++)
				printf("0");
		}
		printf("\n");
	}
	return 0;
}