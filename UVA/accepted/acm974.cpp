#include<stdio.h>
bool st[40005],bu;
long i,j,count,sq,s1,s2,m,n;
int main()
{
	for(i=2;i<40001;i++)
	{
		sq=i*i;

		bu=1;
		for(j=10;j<sq;j*=10)
		{
			s1=sq/j;
			s2=sq%j;
			if(s1+s2==i && s1>0 && s2>0)
			{
				st[i]=1;
				bu=0;
				break;
			}
		}
		if(bu)
			st[i]=0;
	}

	scanf("%ld",&j);
	s1=1;
	while(j--)
	{
		bu=1;
		scanf("%ld%ld",&m,&n);
		count=0;
		printf("case #%ld\n",s1++);
		for(i=m;i<=n;i++)
		{
			if(st[i])
			{
				printf("%ld\n",i);
				bu=0;
			}
		}
		if(bu)
			printf("no kaprekar numbers\n");
		if(j)
			printf("\n");
	}
	return 0;
}