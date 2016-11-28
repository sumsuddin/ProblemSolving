#include<stdio.h>

int main()
{
	long int n,m,i,p;
	char st[1000001],sy[1000001],sum[1000001],d,su[1000001],si[1000001];
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld",&m);
		p=m;
		for(i=0;i<m;i++)
		{
			scanf("%s", &su[i]);
			scanf("%s", &si[i]);
		}

		i=0;
		while(m--)
		{
			st[m]=su[i];
			sy[m]=si[i];
			i++;
		}

		d=0;
		for(i=0;i<p;i++)
		{
			sum[i]=st[i]+sy[i]+d-48;

			if(sum[i]>57)
			{
				sum[i]-=10;
				d=1;
			}
			else
				d=0;
		}
		if(d)
			printf("%d",d);
		while(p--)
			printf("%c",sum[p]);
		printf("\n");
		if(n)
			printf("\n");
	}
	return 0;
}