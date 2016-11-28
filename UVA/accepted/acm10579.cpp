#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
void bigsum(char a[],char b[],char sum[])
{
	long int la,lb,i,j,d=0;

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
	long int i,n;
	char st[100005],sy[100005],su[100005],si[100005];


	while(scanf("%d",&n)==1)
	{
		strcpy(st,"0");
		strcpy(sy,"1");

		for(i=1;i<n;i++)
		{
			strcpy(si,sy);
			bigsum(sy,st,su);
			strcpy(st,si);
			strcpy(sy,su);
		}


		puts(sy);
	}
	return 0;
}
