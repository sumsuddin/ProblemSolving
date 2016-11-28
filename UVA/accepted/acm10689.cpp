#include<stdio.h>
long ans[15],n,m,f0,f1,t,d[15],M,rm[100000][10];
void mul(long a[],long b[])
{
	d[0]=((a[0]*b[0])%M+(a[1]*b[2])%M)%M;
	d[1]=((a[0]*b[1])%M+(a[1]*b[3])%M)%M;
	d[2]=((a[2]*b[0])%M+(a[3]*b[2])%M)%M;
	d[3]=((a[2]*b[1])%M+(a[3]*b[3])%M)%M;
	a[0]=d[0];
	a[1]=d[1];
	a[2]=d[2];
	a[3]=d[3];
}

void pw(long n)
{
	if(n==0)
		return;
	long rc=1,ml[]={1,1,1,0};


	while(n>=2*rc)
	{
		mul(ml,ml);
		rc*=2;
	}
	mul(ans,ml);
	if(n==rc)
		return;
	else
		pw(n-rc);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld%ld",&f0,&f1,&n,&m);

		M=1;
		while(m--)
			M*=10;

		ans[0]=ans[1]=ans[2]=1;
		ans[3]=0;
		n-=2;
		pw(n);
		printf("%ld\n",((ans[0]*f1)%M+(ans[1]*f0)%M)%M);
	}
	return 0;
}