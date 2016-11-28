#include<stdio.h>
#include<string.h>
#include<math.h>

long i,j,n,p,r,k,cs=1,q;
double x[500],y[500],mat[2500][2500],w,mx;
bool flag=0;

double min(double a,double b,double c)
{
	if(b==100000000||c==100000000)
		mx=100000000;
	else
		if(b>=c)
			mx=b;
		else
			mx=c;
	if(a<=mx && a!=100000000 || mx==100000000)
		return a;
	else
		return mx;
}

int main()
{

	while(scanf("%ld",&n) && n)
	{

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=100000000;
		p=1;

		for(i=1;i<=n;i++)
			scanf("%lf%lf",&x[i],&y[i]);


		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				mat[i][j]=w;
				mat[j][i]=w;
			}
		}


		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					mat[i][j]=min(mat[i][j],mat[i][k],mat[k][j]);

				}
			}
		}
		printf("Scenario #%ld\n",cs++);

		printf("Frog Distance = %.3lf\n\n",mat[1][2]);
	}
	return 0;
}
