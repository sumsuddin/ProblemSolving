#include<stdio.h>
long long ans[15],n,m,d[15],M;
void mul(long long a[],long long b[])
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

void pw(long long n)
{
	if(n==0)
		return;
	long long rc=1,ml[]={1,1,1,0};


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
	while(~scanf("%lld%lld",&n,&m))
	{
		M=1;
		while(m--)
			M*=2;
		if(n==0)
      {
         printf("0\n");
         continue;
      }
      else if(n==1)
      {
         printf("%lld\n",1%M);	
         continue;
      }
		ans[0]=ans[1]=ans[2]=1;
		ans[3]=0;
		n-=2;
		pw(n);
		printf("%lld\n",ans[0]%M);
	}
	return 0;
}
