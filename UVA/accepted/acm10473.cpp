#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char st[25];
	long n,i,la;

	while(gets(st))
	{
		if(st[0]==0)
			continue;
		sscanf(st,"%ld",&n);
		if(n<0)
			break;


		
		if(st[0]=='0')
		{
			n=0;
			la=strlen(st)-3;
			for(i=2;st[i];i++)
			{
				if(st[i]>57)
					st[i]-=55;
				else
					st[i]-=48;
				n+=(long)(st[i]*pow(16,la--));

			}
			
			printf("%ld\n",n);
		}
		else
		{

			sscanf(st,"%ld",&n);
			if(n==0)
				printf("0x0\n");
			else
			{
				for(i=0;n;i++)
				{
					st[i]=n%16+48;
					if(st[i]>57)
						st[i]+=7;
					n/=16;
				}
				printf("0x");
				for(i=i-1;i>=0;i--)
					printf("%c",st[i]);
				printf("\n");
			}
		}
	}
	return 0;
}