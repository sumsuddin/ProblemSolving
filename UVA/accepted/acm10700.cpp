#include<stdio.h>
int main()
{
	long double sy[100],sum,n,a,b;
	int i,j,d,p;
	char st[100];
	gets(st);
	sscanf(st,"%llf",&n);

	while(n--)
	{
		gets(st);

		sum=j=0;
		for(i=0;st[i];i++)
		{
			if(st[i]=='+' || st[i]=='*')
			{
				sy[j++]=sum;
				sum=0;
				i++;
			}
			sum=sum*10+(st[i]-48);	

		}
		sy[j]=sum;

		printf("The maximum and minimum are ");

		a=1;b=sy[0];p=1;d=0;

		for(i=0;st[i];i++)
		{
			if(st[i]=='+')
			{
				b+=sy[p++];
			}
			else if(st[i]=='*')
			{
				a*=b;
				b=sy[p++];
			}
		}
		a*=b;
		printf("%.0llf ",a);

		a=0;b=sy[0];p=1;d=0;

		for(i=0;st[i];i++)
		{
			if(st[i]=='*')
			{
				b*=sy[p++];
			}
			else if(st[i]=='+')
			{
				a+=b;
				b=sy[p++];
			}
		}
		a+=b;
		printf("and %.0llf.\n",a);


	}
	return 0;
}