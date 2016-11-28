#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n

long i,n,sum,la,lb;
char st[510][200],sy[200],su[200];

void bigsum(char a[],char b[],char sum[])
{
	long i,j,d=0;

	la=strlen(a);
	lb=strlen(b);

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(a[i],a[j]);


	for(i=0,j=lb-1;i<lb/2;i++,j--)
		swap(b[i],b[j]);
	if(la<lb)
	{
		for(i=la;i<=lb;i++)
			a[i]='0';
		b[lb]='0';
		j=lb;

	}
	else
	{
		for(i=lb;i<=la;i++)
			b[i]='0';
		a[la]='0';
		j=la;
	}

	for(i=0;i<j;i++)
	{
		sum[i]=a[i]+b[i]+d-48;
		if(sum[i]>57)
		{
			sum[i]-=10;
			d=1;
		}
		else
			d=0;
	}
	if(d)
	{
		sum[i]='1';
		sum[i+1]=0;
	}
	else
		sum[i]=0;

	la=strlen(sum);

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(sum[i],sum[j]);

}

int main()
{
	strcpy(su,"1");
	strcpy(st[0],"1");
	strcpy(sy,"2");

	for(i=2;i<500;i++)
	{

		strcpy(st[i-1],sy);
		bigsum(sy,su,st[i]);
		strcpy(su,st[i-1]);
		strcpy(sy,st[i]);
	}

	while(~scanf("%s%s",sy,su) && (sy[0]!='0' || su[0]!='0'))
	{
		sum=0;
		for(i=0;i<500;i++)
		{
			la=strlen(st[i]);
			lb=strlen(sy);
			if((la==lb && strcmp(st[i],sy)>=0) || la>lb)
				break;
		}
		for(i=i;i<500;i++)
		{
			la=strlen(st[i]);
			lb=strlen(su);
			if((la==lb && strcmp(st[i],su)<=0) || la<lb)
				sum++;
			else
				break;
		}
		printf("%ld\n",sum);
	}
	return 0;
}