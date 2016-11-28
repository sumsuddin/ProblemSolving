#include<stdio.h>
long i,n,a[20],max,cs=1;
char st[20][150];
int main()
{
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		max=0;
		printf("Case #%ld:\n",cs++);
		for(i=0;i<10;i++)
		{
			scanf("%s %ld",st[i],&a[i]);
			getchar();
			if(a[i]>max)
				max=a[i];
		}
		for(i=0;i<10;i++)
			if(a[i]==max)
				puts(st[i]);
	}
	return 0;
}