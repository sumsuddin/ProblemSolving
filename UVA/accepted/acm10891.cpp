#include<stdio.h>

long i,a[105],dp[105][105][4],n,j;

long maxv(long a,long b)
{
	return a>b?a:b;
}

long rec(long l,long h,long dir)
{
	if(l>h)
		return 0;

	if(dp[l][h][dir]>-100000000)
		return dp[l][h][dir];

	if(l==h)
		return dp[l][h][dir]=a[l];

	long mx=-100000000;

	if(dir==2)
	{
		if(l==0 && h==3)
		{
		mx=maxv(mx,a[l]+rec(l+1,h,0));
		mx=maxv(mx,a[h]+rec(l,h-1,1));
		mx=maxv(mx,a[l]-rec(l+1,h,2));
		mx=maxv(mx,a[h]-rec(l,h-1,2));
		}
		else
		{
		mx=maxv(mx,a[l]+rec(l+1,h,0));
		mx=maxv(mx,a[h]+rec(l,h-1,1));
		mx=maxv(mx,a[l]-rec(l+1,h,2));
		mx=maxv(mx,a[h]-rec(l,h-1,2));
		}
	}
	else if(dir==1)
	{
		mx=maxv(mx,a[h]+rec(l,h-1,1));
		mx=maxv(mx,a[h]-rec(l,h-1,2));
	}
	else
	{
		mx=maxv(mx,a[l]+rec(l+1,h,0));
		mx=maxv(mx,a[l]-rec(l+1,h,2));
	}

	return dp[l][h][dir]=mx;
}

int main()
{
	while(scanf("%ld",&n) && n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(a[0]=0;a[0]<3;a[0]++)
					dp[i][j][a[0]]=-100000000;

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		printf("%ld\n",rec(0,n-1,2));
	}
	return 0;
}
