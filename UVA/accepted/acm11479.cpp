#include<stdio.h>

int main()
{
	long int a,b,c,n,max,i;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld%ld%ld",&a,&b,&c);

		printf("Case %ld: ",i);
		max=a;
		if(max<b)
			max=b;
		if(max<c)
			max=c;

		if((a+b+c-max)<=max)
			printf("Invalid\n");
		else
			if(a==b && a==c)
				printf("Equilateral\n");
			else
				if(a==b || a==c || b==c)
					printf("Isosceles\n");
				else
					printf("Scalene\n");
				
	}
	return 0;
}
