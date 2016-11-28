#include<stdio.h>
long i,n,k,dn[1000050],nm[1000050],g,next[1000050],lst;

long gcd(long a,long b)
{
	long c=a%b;

	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}


void call(long l,long h)
{
	long pp,num,dnum;
	num=nm[l]+nm[h];
	dnum=dn[l]+dn[h];

	g=gcd(num,dnum);
	num/=g;
	dnum/=g;
	if(num<=n && dnum<=n)
	{
		next[l]=lst;
		next[lst]=h;
		nm[lst]=num;
		dn[lst]=dnum;
		pp=lst++;

		call(l,pp);
		call(pp,h);
	}
}

int main()
{
	while(~scanf("%ld%ld",&n,&k))
	{
		next[0]=1;
		nm[0]=0,nm[1]=1;
		dn[0]=dn[1]=1;

		lst=2;

		call(0,1);
		n=0;
		for(i=0;i<k;i++)
			n=next[n];
		printf("%ld/%ld\n",nm[n],dn[n]);
	}
	return 0;
}