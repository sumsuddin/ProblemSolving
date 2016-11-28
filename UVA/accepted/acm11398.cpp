#include<stdio.h>
#include<string.h>
#include<math.h>
long i,j,la,p,sum;
bool fg,sy[1000];
char st[150];

int main()
{
	while(scanf("%s",st) && st[0]!='~')
	{
		if(st[0]=='#')
		{
			sum=0;
			fg=0;
			for(i=0,j=p-1;i<p;i++,j--)
				sum+=sy[j]*pow(2,i);
			p=0;
			printf("%ld\n",sum);
		}
		else
		{
			la=strlen(st);
			if(la==1)
				fg=1;
			else
				if(la==2)
					fg=0;
				else
				{
					for(i=2;i<la;i++)
						sy[p++]=fg;
				}
		}
	}
	return 0;
}