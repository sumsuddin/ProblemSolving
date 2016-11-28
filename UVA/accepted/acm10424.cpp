#include<stdio.h>
#include<string.h>

long int add(long int a)
{
	long int sum=0,c,d;
	for(;a>=1;)
	{	
		c=a%10;
		sum+=c;
		a=a/10;
	}
	if(sum>9)
		add(sum);

	if(sum<=9)
	return sum;
}


void main()
{
	char st[100000],sy[100000];
	long int a,b,c,d,sum1=0,sum2=0,i,e;
	double ans;

	while(	gets(st) && gets(sy))
	{
		sum1=sum2=d=0;
		a=strlen(st);
		b=strlen(sy);
	
	for(i=0;i<a;i++)
	{
		if(st[i]>=97 && st[i]<=122)
			d=96;
		
		else
		{
			if(st[i]>=65&& st[i]<=90)
			d=64;
			else
				continue;
		}

		sum1=sum1+st[i]-d;
	}
	for(i=0;i<b;i++)
	{
		if(sy[i]>=97 && sy[i]<=122)
			d=96;
		else
		{
			if(sy[i]>=65&& sy[i]<=90)
				d=64;
			else
				continue;
		}

		sum2=sum2+sy[i]-d;
	}



		if(sum1>9)
			sum1=add(sum1);
		if(sum2>9)
			sum2=add(sum2);

		if(sum1>sum2)
			ans=((double)sum2/(double)sum1);
		else
			ans=((double)sum1/(double)sum2);
		ans=ans*100;

		printf("%.2lf %c\n",ans,37);
	}
}