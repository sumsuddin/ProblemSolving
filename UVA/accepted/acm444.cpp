#include<stdio.h>
#include<string.h>
char st[500],sy[500];
int main()
{
	long i,j,la,sum;

	while(gets(st))
	{
		if(st[0]==0)
		{
			printf("\n");

			continue;
		}
		sum=j=0;
		if(st[0]>47 && st[0]<58)
		{
			la=strlen(st);

			for(i=la-1;i>=0;i--)
			{
				sum=sum*10+(st[i]-48);
				if(sum>30 && sum<130)
				{
					printf("%c",(char)sum);
					sum=0;
				}
			}
			printf("\n");

		}
		else
		{
			la=strlen(st);
			while(la--)
			{
				while(st[la])
				{
					sy[j++]=(st[la]%10)+48;
					st[la]/=10;
				}
				sy[j]=0;
			}
			puts(sy);
		}
	}
	return 0;
}