#include<stdio.h>
#include<string.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n

char hex1[10000];
long h1,i,j,c,to,d;

void rev(char a[])
{
	d=h1=strlen(a);
	d/=2;
	for(i=0,j=h1-1;i<d;i++,j--)
	{
		swap(a[i],a[j]);
	}
}

int main()
{
	while(scanf("%s %ld %ld",hex1,&c,&to)==3)
	{
		h1=0;

		for(i=strlen(hex1)-1,j=0;i>=0;i--,j++)
		{
			if(hex1[i]>64)
				hex1[i]-=55;
			else
				hex1[i]-=48;

			h1+=(long)(hex1[i]*pow(c,j));
		}
			for(i=0;h1 && i<7;i++)
			{
				hex1[i]=((h1%to)+48);

				if(hex1[i]>57)
					hex1[i]+=7;

				h1/=to;
			}

			if(h1)
			{
				printf("  ERROR\n");
				continue;
			}

			for(;i<7;i++)
				hex1[i]=' ';
			hex1[i]=0;
			rev(hex1);
			if(strcmp(hex1,"       ")==0)
				puts("      0");
			else
				puts(hex1);
	}
	return 0;
}