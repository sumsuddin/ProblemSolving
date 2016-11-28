#include<stdio.h>
long a,n,t,bu[120],flag,cs=1,i,j;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		flag=0;
		scanf("%ld",&n);
		for(i=0;i<=100;i++)
			bu[i]=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%ld",&a);
				bu[a]++;
				if(bu[a]>n)
					flag=1;
			}
		if(flag)
			printf("Case %ld: no\n",cs++);
		else
			printf("Case %ld: yes\n",cs++);
	}
	return 0;
}