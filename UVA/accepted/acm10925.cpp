#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n

	char st[500],sy[500];
	long la,lb,i,j,d,m,n,pa=1;

void division(char a[],long *b)
{
	long i,ex;
	for(i=0,ex=0;a[i];i++)
	{
		ex=ex*10+(a[i]-48);
		a[i]=ex/ *b+'0';
		ex=ex%*b;
	}
}

void bigsum(char a[],char b[])
{
	d=0;

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
	while(gets(sy))
	{
		strcpy(st,"0");
		i=1;
		sscanf(sy,"%ld%ld",&n,&m);
		if(!n || !m)
			break;

		while(n--)
		{
			gets(sy);
			bigsum(st,sy);
		}
		printf("Bill #%ld costs %s: each friend should pay ",pa++,st);
		division(st,&m);

		j=0;
		for(i=0;st[i]=='0';i++);
		for(i;st[i];i++)
            st[j++]=st[i];
		st[j]=0;
        if(!st[0])
        {
			st[0]='0';
			st[1]=0;
		}
		printf("%s\n\n",st);
	}
	return 0;
}
