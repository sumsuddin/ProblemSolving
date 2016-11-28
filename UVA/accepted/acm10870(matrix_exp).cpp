#include<cstdio>
#include<cmath>
typedef long long ind;
long long a,b,c,i,j,k;
ind M[50][50],F[50][50],D[50][50],FF[50][50],s,m,t;
void check(long long n)
{
	if(n<=1)
		return ;

	if(n%2==0)
		check(n/2);
	else
		check(n-1);
	if(n%2==0)
	{
		for(i=0;i<t;i++)
		{
			for(j=0;j<t;j++)
			{
				s=0;
				for(k=0;k<t;k++)
				{
					s+=(M[i][k]*M[k][j])%m;
					s=s%m;
				}
				D[i][j]=s%m;
			}
		}
	}
	else
	{
		for(i=0;i<t;i++)
		{
			for(j=0;j<t;j++)
			{
				s=0;
				for(k=0;k<t;k++)
				{
					s+=(M[i][k]*F[k][j])%m;
					s=s%m;
				}
				D[i][j]=s%m;
			}
		}
	}
	for(i=0;i<t;i++)
		for(j=0;j<t;j++)
			M[i][j]=D[i][j];
}



int main()
{
	long long n,a[50],f[50];
	while(~scanf("%lld%lld%lld",&t,&n,&m) && (t|| m || n))
	{
		for(i=0;i<t;i++)
			scanf("%lld",&a[i]);

		for(i=0;i<t;i++)
			scanf("%lld",&f[i]);

		if(n<=t)
		{
			printf("%lld\n",f[n-1]%m);
			continue;
		}
		for(i=0;i<t;i++)
			for(j=0;j<t;j++)
				M[i][j]=F[i][j]=0;

		for(i=0;i<t;i++)
			M[0][i]=F[0][i]=a[i];
		for(i=1;i<t;i++)
			M[i][i-1]=F[i][i-1]=1;

		check(n-t);
		
		j=0;
		for(i=0,b=t-1;i<t;i++,b--)
			j=(j+(M[0][i]*f[b])%m)%m;

		printf("%lld\n",j);
		
	}
	return 0;
}
