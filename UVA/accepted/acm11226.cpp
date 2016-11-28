#include<stdio.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n
long sum[500005],sq,count,k,i,j,p,n,m,ans;

int main()
{
	for(i=2;i<=500001;i++)
	{
		k=i;
		while(k%2==0)
		{
			k/=2;
			sum[i]+=2;
		}
		sq=sqrt(k)+1;
		for(j=3;j<sq;j+=2)
		{
			while(k%j==0)
			{
				k/=j;
				sum[i]+=j;
			}
		}
		if(k!=1)
			sum[i]+=k;
	}

	scanf("%ld",&k);
	for(p=1;p<=k;p++)
	{
		scanf("%ld%ld",&m,&n);
		if(n<m)
			swap(m,n);
		ans=0;
		for(i=m;i<=n;i++)
		{
			j=i;count=1;
			while(sum[j]!=j)
			{
				j=sum[j];
				count++;
			}
			if(count>ans)
				ans=count;
		}
		printf("Case #%ld:\n%ld\n",p,ans);
	}
	return 0;
}