#include<stdio.h>
#include<string.h>
int a[100],d;
long i,j,l,p,m;
char st[100],sy[100];
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
}

int main()
{
	while(~scanf("%s%ld",st,&p))
	{
		d=0;
		for(i=strlen(st)-1;i>=0;i--)
			if(st[i]=='.')
				break;
			else
				d++;

		for(;st[i];i++)
			st[i]=st[i+1];

		d*=p;

		sscanf(st,"%ld",&m);

		fpow(m,p);

		m=l-d;

		for(i=l-1,j=0;j<m;i--,j++)
			st[j]=a[i]+'0';
		st[j]='.';
		st[j+1]=0;

		for(j=0;i>=0;i--,j++)
			sy[j]=a[i]+'0';
		sy[j]=0;
		m=strlen(sy);
		if(m<d)
		{
			d-=m;
			j=strlen(st);
			for(i=0;i<d;i++)
				st[i+j]='0';
			st[i+j]=0;
		}
		while(sy[m-1]=='0')
			m--;
		sy[m]=0;

		printf("%s%s\n",st,sy);
	}
	return 0;
}