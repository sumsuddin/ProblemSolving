#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n
long i,j,l;

char c,s[1000000],sum[1000000],st[1000000],sy[1000000];

void bsum(char a[],char b[])
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

void multi(char a[],char b[])
{
	long int la=strlen(a),lb=strlen(b),i,j,d,carry,test=0,we=la;

	char se;

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(a[i],a[j]);


	for(i=0,j=lb-1;i<lb/2;i++,j--)
		swap(b[i],b[j]);


	for(i=0;i<lb;i++)
	{
			d=carry=0;

		for(j=0;j<we;j++)
		{

			s[j]=(a[j]-'0') * (b[i]-'0')+d;
			if(s[j]>9)
			{
				se=s[j];
				d=se/10;
				s[j]=(se%10);
			}
			else
				d=0;
			


		}



		if(d>0)
		{
			s[we]=d;
		}


		for(j=la;j>=0 && test!=0;j--)
		{
			s[j+test-1]=s[j-1];
		}

		for(j=0;j<test;j++)
			s[j]=0;

		for(j=0;j<la;j++)
		{
			if(i==0)
				sum[j]=0;
			sum[j]=sum[j]+s[j]+carry;
			if(sum[j]>9)
			{
				sum[j]=sum[j]-10;
				carry=1;
				
				
			}	
			else
				carry=0;
			s[j]=0;

		}
		if(carry>0 || d>0)
		{
			sum[j]=carry+d;
			sum[j+1]=0;
		}
		else
			sum[j]=0;
		
			
		

	test++;la++;

	}
	if(sum[la-1]>9 || sum[la-1]<=0)
		la=la-1;

	for(i=0,j=la-1;j>=0;i++,j--)
		a[i]=sum[j]+48;
	a[i]=0;
}

int main()
{
	while(~scanf("%s %c %s",st,&c,sy))
	{
		printf("%s %c %s\n",st,c,sy);

		i=0;
		while(st[i]=='0')
			i++;
		strcpy(st,st+i);

		if(st[0]==0)
		{
			st[0]='0';
			st[1]=0;
		}

		i=0;
		while(sy[i]=='0')
			i++;
		strcpy(sy,sy+i);

		if(sy[0]==0)
		{
			sy[0]='0';
			sy[1]=0;
		}

		l=strlen(st);

		if(l>10)
			printf("first number too big\n");
		else
			if(l==10 && strcmp(st,"2147483647")>0)
				printf("first number too big\n");
		l=strlen(sy);

		if(l>10)
			printf("second number too big\n");
		else
			if(l==10 && strcmp(sy,"2147483647")>0)
				printf("second number too big\n");

		if(c=='+')
			bsum(st,sy);
		else
			multi(st,sy);

		i=0;
		while(st[i]=='0')
			i++;
		strcpy(st,st+i);

		l=strlen(st);

		if(l>10)
			printf("result too big\n");
		else
			if(l==10 && strcmp(st,"2147483647")>0)
				printf("result too big\n");

	}
	return 0;
}