#include<stdio.h>
#include<math.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n

long a[1000],l,i,p,j,d,la,lb,n,mlt,t;
char st[1000],ans[1000];

void fpow(long mlt,long n)
{
	a[0]=l=1;
	for(i=0;i<n;i++)
	{
		p=0;
		for(j=0;j<l;j++)
			a[j]*=mlt;
		for(j=0;j<l;j++)
		{
			if(a[j]/10)
			{
				if(j<l-1)
					a[j+1]+=a[j]/10;
				else
				{
					a[j+1]=a[j]/10;
					p++;
				}
			}
			a[j]=a[j]%10;
		}
		l+=p;
		if((p=a[l-1])>9)
		{
			l--;
			while(p)
			{
				a[l++]=p%10;
				p/=10;
			}
		}
	}
		p=0;
		for(j=0;j<l;j++)
			a[j]*=n;
		for(j=0;j<l;j++)
		{
			if(a[j]/10)
			{
				if(j<l-1)
					a[j+1]+=a[j]/10;
				else
				{
					a[j+1]=a[j]/10;
					p++;
				}
			}
			a[j]=a[j]%10;
		}
		l+=p;
		if((p=a[l-1])>9)
		{
			l--;
			while(p)
			{
				a[l++]=p%10;
				p/=10;
			}
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
	while(~scanf("%ld %ld",&n,&mlt))
	{
		strcpy(ans,"0");
		for(t=1;t<=n;t++)
		{
			fpow(mlt,t);
			i=0;
			while(l--)
				st[i++]=a[l]+'0';
			st[i]=0;
			bigsum(ans,st);
		}
		puts(ans);
	}
	return 0;
}