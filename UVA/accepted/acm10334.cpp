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
	char st[1009][1000],sy[1000],su[1000];
	strcpy(su,"1");
	strcpy(st[0],"1");
	strcpy(sy,"1");

	for(i=1;i<1002;i++)
	{

		strcpy(st[i-1],sy);
		bigsum(sy,su,st[i]);
		strcpy(su,st[i-1]);
		strcpy(sy,st[i]);
	}

	while(scanf("%d",&n)==1)
	{
		printf("%s\n",st[n]);
	}
	return 0;
}