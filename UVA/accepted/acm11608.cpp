#include<stdio.h>
int main()
{
	long int a,n,st[15],p=1,i;

	while(scanf("%ld",&n))
	{
		if(n<0)
			break;

		for(i=0;i<12;i++)
			scanf("%ld",&st[i]);

		for(i=0;i<12;i++)
		{
			if(i)
			n+=st[i-1];
			else
				printf("Case %ld:\n",p++);


			scanf("%ld",&a);

			if(n<a)
				printf("No problem. :(\n");
			else
			{
				printf("No problem! :D\n");
				n-=a;
			}
		}
	}
	return 0;
}