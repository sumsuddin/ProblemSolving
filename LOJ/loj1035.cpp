#include<stdio.h>
long i,vc[110][110],lst,pr[110],cs=1,n,t,j,bc;
bool bu[110],flag;
int main()
{
	pr[0]=2;
	lst=1;
	for(i=3;i<101;i+=2)
	{
		if(bu[i]==0)
		{
			pr[lst++]=i;
			for(j=3*i;j<101;j+=(2*i))
				bu[j]=1;
		}
	}
	scanf("%ld",&t);

	for(i=2;i<101;i++)
	{
		for(j=0;j<=i;j++)
			vc[i][j]=vc[i-1][j];

		if(i==97)
			i=i;

		bc=i;
		for(j=0;pr[j]<=i && j<lst;j++)
		{
			while(bc%pr[j]==0)
				vc[i][pr[j]]++,bc/=pr[j];
		}
	}

	while(t--)
	{
		scanf("%ld",&n);

		printf("Case %ld: %ld =",cs++,n);

		flag=1;
		for(i=0;pr[i]<=n;i++)
		{
			if(vc[n][pr[i]] && i<lst)
			{
				if(flag)
					flag=0;
				else
					printf(" *");
				printf(" %ld (%ld)",pr[i],vc[n][pr[i]]);
			}
		}
		printf("\n");
	}
	return 0;
}