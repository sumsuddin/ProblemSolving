#include<stdio.h>
#include<string.h>
#include<math.h>
char *st[15]={""," shata"," hajar"," lakh"," kuti"," shata"," hajar"," lakh"," kuti"};
int a[9]={2,1,2,2,2,1,2,2,2};

int main()
{
	long i,j,d,p,la,n,m=1;
	int b[1000];
	char sy[1000];
	while(gets(sy))
	{
		printf("%4ld.",m++);
		p=0;n=1;
		la=strlen(sy);
		for(i=la;i>0;i--)
		{
			b[p]=0;
			for(j=i-1,d=0;j>=i-a[p] && j>=0;j--,d++)
			{
				b[p]+=(long)((sy[j]-48)*pow(10,d));
			}
			i-=(a[p]-1);
			p++;
		}
		for(i=p-1;i>=0;i--)
			if(b[i]!=0)
			{
				printf(" %d%s",b[i],st[i]);
				n=0;
			}
			else
				if(!strcmp(st[i]," kuti"))
				{
					if(!n)
					{
						printf(" kuti");
						n=0;
					}
				}
		if(n)
			printf(" 0");
		printf("\n");
	}
	return 0;
}