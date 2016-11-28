#include<stdio.h>
#include<math.h>
long i,j,x[10000],y[10000],n,k,t,cs=1;
double st[2000][2000],mx,d1,d2,d3;

bool check(double ans)
{
	ans=(ans*1e4 - floor(ans*1e4) - 0.5);
	if(ans<0)
		ans*=-1;
	return ans>1e-2;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
		{
			scanf("%ld%ld",&x[i],&y[i]);
			for(j=1;j<=n;j++)
				st[i][j]=100000000;
		}

		for(k=1;k<=n;k++)

		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					d1=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
					if(d1<st[i][j] && d1<=10.0)
						st[i][j]=d1;

					d2=st[i][k];
					d3=st[k][j];
					if(st[i][j]>d2+d3)
						st[i][j]=d2+d3;
				}
			}
		}
		mx=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(st[i][j]>mx)
					mx=st[i][j];
		if(mx==100000000.0)
			printf("Case #%ld:\nSend Kurdy\n\n",cs++);
		else
			printf("Case #%ld:\n%.4lf\n\n",cs++,mx+1e-8);
	}
	return 0;
}