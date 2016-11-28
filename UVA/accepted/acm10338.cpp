#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
long double fect(long double a)
{
	long double b=1,i;
	for(i=2;i<=a;i++)
		b*=i;
	return b;
}
int main()
{
	long n,i,j,q=1;
	long double a,p;
	char st[100],c;

	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		gets(st);

		a=strlen(st);
		
		a=fect(a);

		for(i=0;st[i];i++)
		{
			for(j=i+1;st[j];j++)
				if(st[i]>st[j])
					swap(st[i],st[j]);
		}
		c=st[0];p=1;
		for(i=1;st[i];i++)
		{
			if(c==st[i])
				p++;
			else
			{
				a/=fect(p);
				c=st[i];
				p=1;
			}
		}
		a/=fect(p);
		printf("Data set %ld: %.0llf\n",q++,a);
	}
	return 0;
}