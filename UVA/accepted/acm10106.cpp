#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
void bigmulti(char a[],char b[],char s[],char sum[])
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
	char st[1000],sy[1000],s[1000],sum[1000],d;
	int i;

	while(gets(st),gets(sy))
	{
		bigmulti(st,sy,s,sum);
		d=1;
		for(i=0;st[i];i++)
			if(st[i]!='0')
				break;
		for(i;st[i];i++)
		{
			printf("%c",st[i]);
			d=0;
		}

		if(d)
			printf("0\n");
		else
			printf("\n");
	}
	return 0;
} 