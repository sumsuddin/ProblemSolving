#include<stdio.h>
#include<string.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n

char hex1[50],hex2[50],c,st[100];
long sum,h1,h2,i,j,n;

void rev(char a[])
{
	for(i=0,j=12;i<6;i++,j--)
	{
		swap(a[i],a[j]);
	}
}

int main()
{
	gets(st);
	sscanf(st,"%ld",&n);

	while(n--)
	{
		gets(st);

		sscanf(st,"%s %c %s",hex1,&c,hex2);
		h1=h2=0;

		for(i=strlen(hex1)-1,j=0;i>=0;i--,j++)
		{
			if(hex1[i]>64)
				hex1[i]-=55;
			else
				hex1[i]-=48;

			h1+=(long)(hex1[i]*pow(16,j));
		}
		for(i=strlen(hex2)-1,j=0;i>=0;i--,j++)
		{
			if(hex2[i]>64)
				hex2[i]-=55;
			else
				hex2[i]-=48;

			h2+=(long)(hex2[i]*pow(16,j));
		}

		if(c=='+')
			sum=h1+h2;
		else
			sum=h1-h2;

		for(i=0;h1;i++)
		{
			hex1[i]=((h1%2)+48);
			h1/=2;
		}
		for(;i<13;i++)
			hex1[i]=48;
		hex1[i]=0;

		for(i=0;h2;i++)
		{
			hex2[i]=((h2%2)+48);
			h2/=2;
		}
		for(;i<13;i++)
			hex2[i]=48;
		hex2[i]=0;

		rev(hex1);
		rev(hex2);

		printf("%s %c %s = %ld\n",hex1,c,hex2,sum);
	}
	return 0;
}