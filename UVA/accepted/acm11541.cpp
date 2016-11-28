#include<stdio.h>
#include<ctype.h>
int main()
{
	char st[1000],c;
	long int i,j,sum,n,p=1;

	gets(st);
	sscanf(st,"%ld",&n);

	while(n--)
	{
		gets(st);
		sum=0;
		printf("Case %ld: ",p++);
		for(i=0;st[i];i++)
		{
			if(st[i]>47 && st[i]<58)
			{
				sum=(sum*10)+(st[i]-48);
				if(isdigit(st[i+1]))
					continue;
			}
			else
			{
				if(st[i]>64 && st[i]<91)
					c=st[i];
			}
			for(j=0;j<sum;j++)
				printf("%c",c);
			sum=0;

		}
		printf("\n");
	}
	return 0;
}
