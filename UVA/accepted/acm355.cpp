#include<stdio.h>
#include<string.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n

char hex1[50];
long h1,i,j,c,to,d;
bool flag;

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
	while(gets(hex1))
	{
		flag=1;
		h1=0;

		sscanf(hex1,"%ld %ld %s",&c,&to,hex1);

		printf("%s ",hex1);

		if(hex1[0]=='0')
		{
			printf("base %ld = %s base %ld\n",c,hex1,to);
			continue;
		}

		for(i=strlen(hex1)-1,j=0;i>=0;i--,j++)
		{
			if(hex1[i]>64)
				hex1[i]-=55;
			else
				hex1[i]-=48;
			if(hex1[i]>=c)
			{
				flag=0;
				break;
			}
			else
				h1+=(long)(hex1[i]*pow(c,j));
		}

		i=0;
		while(h1)
		{
			d=h1%to;
			h1/=to;
			if(d>9)
				hex1[i++]=(char)(d+55);
			else
				hex1[i++]=(char)(d+48);
		}
		hex1[i]=0;
		if(flag)
		{
			rev(hex1);
			printf("base %ld = %s base %ld\n",c,hex1,to);
		}
		else
			printf("is an illegal base %ld number\n",c);
	}

	return 0;
}