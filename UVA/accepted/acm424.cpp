#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
void bigsum(char a[],char b[])
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
		a[i]=a[i]+b[i]+d-48;
		if(a[i]>57)
		{
			a[i]-=10;
			d=1;
		}
		else
			d=0;
	}
	if(d)
	{
		a[i]='1';
		a[i+1]=0;
	}
	else
		a[i]=0;

	la=strlen(a);

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(a[i],a[j]);

}

int main()
{
	char st[1000][1000];
	int i=1;
	strcpy(st[0],"0");
	while(gets(st[i]))
	{
		if(!strcmp(st[i],"0"))
			break;
		bigsum(st[0],st[i]);

		i++;
	}
	puts(st[0]);
	return 0;
}