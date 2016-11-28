#include<stdio.h>

long i,l,h,mid,t,n,d,ds[140],mx,cs=1;
char c,st[100];
bool flag,vis[140],prmn[140];

long bfs(long p)
{
	long i;

	for(i=p+1;i<=h;i++)
	{
		if(ds[i]-ds[p]>mid)
			break;

		if(vis[i])
		{
			vis[i]=0;
			if(i==h)
				bfs(0);
			else
				bfs(i);
			vis[i]=1;
		}
		else if(i==h)
			flag=1;
	}
	return 1;
}

long bsrch(long low,long h)
{
	while(low<h)
	{
		mid=(low+h)/2;

		flag=0;
		if(bfs(l) && flag)
			h=mid;
		else
			low=mid+1;
	}
	return (low+h)/2;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&d);

		vis[0]=1;
		for(i=1;i<=n;i++)
		{
			vis[i]=1;
			scanf("%s",st);

			sscanf(st,"%c-%ld",&c,&ds[i]);

			if(c=='S')
				prmn[i]=0;
			else
				prmn[i]=1;
		}
		vis[n+1]=1;
		ds[0]=0;
		ds[n+1]=d;
		prmn[n+1]=1;
		prmn[0]=1;

		h=0;
		mx=0;
		while(h<=n+1)
		{
			l=h;
			h++;
			while(prmn[h]==0 && h<=n+1)
				h++;
			d=bsrch(0,ds[h]-ds[l]);
			if(d>mx)
				mx=d;
		}
		printf("Case %ld: %ld\n",cs++,mx);
	}
	return 0;
}
