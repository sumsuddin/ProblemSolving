#include<stdio.h>
#include<string.h>

long long n,m,d,carry,i,j,t,l2,ans;
char st[100],ss[100],sl[100],c;

void multiply(char ss[],char sr[])
{
	long long l1=strlen(ss);
	long long l2=strlen(sr);

	for(i=0;i<100;i++)
		sl[i]=0;

	for(i=0;i<l1;i++)
	{
		carry=d=0;
		for(j=0;j<l2;j++)
		{
			c=(ss[i]-'0')*(sr[j]-'0');
			carry=c/10;
			c%=10;
			sl[i+j]+=(c+d);
			if(sl[i+j]<'0')
				sl[i+j]+='0';
			d=carry;
		}
		if(d>0)
			sl[i+j]+=d;
		if(sl[i+j]<'0')
			sl[i+j]+='0';

		carry=0;
		for(j=0;j<100;j++)
		{
			sl[j]+=carry;
			if(sl[j]>'9')
				carry=(sl[j]-'0')/10,sl[j]=(sl[j]-'0')%10+'0';
			else
				carry=0;
		}
		if(carry)
			sl[j]=carry+'0';
	}
	l2=strlen(sl);
	while(sl[l2-1]=='0' && l2)
		l2--;
	i=l2-20;
	if(i<0)
		i=0;

	for(j=0;i<l2;i++,j++)
		ss[j]=sl[i];
	ss[j]=0;

}

void lead(long long m)
{
	if(m==0)
	{
		ss[0]=1;
		ss[1]=0;
		return;
	}
	if(m==1)
	{
		strcpy(ss,st);
		return;
	}

	if(m%2)
	{
		lead(m-1);
		multiply(ss,st);
	}
	else
	{
		lead(m/2);
		multiply(ss,ss);
	}
}

void mod(long long m)
{
	if(m==0)
	{
		ans*=1;
		return;
	}
	else if(m==1)
	{
		ans*=n;
		ans%=1000;
		return;
	}
	else
	{
		if(m%2)
		{
			mod(m-1);
			ans*=n;
			ans%=1000;
		}
		else
		{
			mod(m/2);
			ans*=ans;
			ans%=1000;
		}
	}
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%s%lld",st,&m);

		n=0;
		ans=1;
		for(i=0;st[i];i++)
			n=n*10+(st[i]-'0');
		mod(m);

		for(i=0,j=strlen(st)-1;i<j;i++,j--)
		{
			c=st[i];
			st[i]=st[j];
			st[j]=c;
		}
		lead(m);
		l2=strlen(ss);
		while(ss[l2-1]=='0' && l2)
			l2--;

		i=l2-3;
		if(i<0)
			i=0;
		n=0;
		for(j=l2-1;j>=i;j--)
			n=n*10+(ss[j]-'0');
		printf("%03lld...%03lld\n",n,ans);
	}
	return 0;
}
