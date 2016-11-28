#include<stdio.h>
#define swap(m,n)m^=n^=m^=n

bool bu[1000010],vst[1000010];
long i,j,bc[15],p,d,pr[1000010],flag,a,b,l;
char st[15],c;

void sieve()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<1000001;i+=2)
		bu[i]=1;

	for(i=3;i<1000001;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<1000001;j+=i)
				bu[j]=1;
		}
	}
}

void check()
{
	for(i=100;i<1000001;i++)
	{
		if(vst[i]==0 && bu[i]==0)
		{
			p=i;
			j=flag=0;
			while(p)
			{
				st[j++]=(p%10)+'0';
				p/=10;
			}
			st[j]=0;

			for(p=0,l=j-1;p<j/2;p++,l--)
				swap(st[p],st[l]);

			p=0;
			for(l=0;l<j;l++)
				p=p*10+(st[l]-'0');

			while(vst[p]==0 && bu[p]==0)
			{
				vst[p]=1;

				bc[flag++]=p;
				
				c=st[0];
				for(l=1;l<j;l++)
					st[l-1]=st[l];
				st[l-1]=c;

				p=0;
				for(l=0;l<j;l++)
					p=p*10+(st[l]-'0');
			}

			if(flag==j)
				for(i=0;i<j;i++)
					pr[bc[i]]=1;
		}
	}
	for(i=100;i<1000001;i++)
		pr[i]+=pr[i-1];
}

int main()
{
	sieve();

	check();

	while(scanf("%ld",&a) && a!=-1)
	{
		scanf("%ld",&b);
		if(a%2)
			a--;
		if(b%2)
			b++;

		if(pr[b]-pr[a]==1)
			printf("%ld Circular Prime.\n",pr[b]-pr[a]);
		else if(pr[b]-pr[a]==0)
			printf("No Circular Primes.\n");
		else
			printf("%ld Circular Primes.\n",pr[b]-pr[a]);

	}
	return 0;
}