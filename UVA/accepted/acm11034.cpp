#include<stdio.h>
#include<string.h>
long n,m,a,count,t,l,r,lc,rc,lf[100010],ri[100010],i;
char st[20];
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		l=r=lc=rc=0;
		scanf("%ld%ld",&n,&m);
		n*=100;
		while(m--)
		{
			scanf("%ld%s",&a,st);
			if(strcmp(st,"right")==0)
				ri[r++]=a;
			else
				lf[l++]=a;
		}
		i=m=0;
		while(i<l)
		{
			while(i<l && m+lf[i]<=n)
				m+=lf[i++];
			m=0;
			lc++;
		}

		i=m=0;
		while(i<r)
		{
			while(i<r && m+ri[i]<=n)
				m+=ri[i++];
			m=0;
			rc++;
		}

		if(lc>rc)
		{
			count=lc*2-1;
		}
		else
		{
			count=rc*2;
		}
		printf("%ld\n",count);
	}
	return 0;
}