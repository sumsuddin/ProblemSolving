#include<stdio.h>
long st[10005],i;
long gdc(long *a,long *b)
{
	long c;

	for(i=0;;i++)
	{
		c=*a%*b;
		st[i]=*a/ *b;
		if(c==0)
		{
			return i;
			break;
		}
		*a=*b;
		*b=c;
	}
}
int main()
{
	long int a,b,c=1,x,y,e,f;
	while(scanf("%ld%ld",&a,&b)==2)
	{
		e=a;
		f=b;
		x=1;y=0;
		c=gdc(&a,&b);
		a=1;
		for(i=c-1;i>=0;i--)
		{
			if(a==1)
				y+=x*st[i];
			else
				x+=st[i]*y;
			a*=-1;
		}


		if(x<y)
		{
			a=x;
			x=y;
			y=a;
		}
		if(e>=f)
		{
			a=x;
			x=y;
			y=a;
		}

		if((x*e-y*f)==b)
			y*=-1;
		else
			x*=-1;

		printf("%ld %ld %ld\n",x,y,b);

	}
	return 0;
}