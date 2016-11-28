#include<stdio.h>
#include<math.h>
int prime(long *a)
{
	if(*a==1)
		return 0;
	else if(*a==2)
		return 1;
	long b=(long)sqrt(*a)+1,i;
	if(*a%2==0)
		return 0;
	else
		for(i=3;i<b;i++)
		{
			if((*a%i)==0)
			{
				return 0;
				break;
			}
		}
	return 1;
}
int main()
{
	char st[2005],sy[2005],c;
	long e,d,i,n,m,num[200],p=1;

	gets(st);
	sscanf(st,"%ld",&n);
	for(i=48;i<123;i++)
		num[i]=0;
	while(n--)
	{
		gets(st);
		printf("Case %ld: ",p++);
		c=st[0];d=m=0;e=1;
		for(i=0;st[i];i++)
		{
			num[st[i]]++;

		}
		for(i=48;i<123;i++)
		{
			if(num[i]>0 && prime(&num[i]))
				sy[m++]=i;
			num[i]=0;
		}
		sy[m]=0;
		for(i=0;sy[i];i++)
		{
			for(d=i+1;sy[d];d++)
				if(sy[i]>sy[d])
				{
					c=sy[i];
					sy[i]=sy[d];
					sy[d]=c;
				}
		}
		if(!sy[0])
			printf("empty\n");
		else
			puts(sy);
	}
	return 0;
}
