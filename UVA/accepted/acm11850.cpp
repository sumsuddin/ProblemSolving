#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
long st[100005],i,j,n,d;
int main()
{
	while(scanf("%ld",&n),n)
	{
		st[0]=0;d=1;
		for(i=1;i<=n;i++)
			scanf("%ld",&st[i]);
		st[++n]=1422;

		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
				if(st[i]>st[j])
					swap(st[i],st[j]);
		}
		for(i=1;i<n;i++)
		{
			if((st[i]-st[i-1])>200)
			{
				printf("IMPOSSIBLE\n");
				d=0;
				break;
			}
		}
		if(d)
		{
			if(st[n]-st[n-1]>100)
			{
				printf("IMPOSSIBLE\n");
				d=0;
			}
		}

		if(d)
			printf("POSSIBLE\n");
	}
	return 0;
}