#include<stdio.h>
#include<math.h>
bool flag;
long i,n;
int main()
{
	while(scanf("%ld",&n),n)
	{
		flag=1;
		for(i=1;i<31;i++)
			if(n==(long)(pow(2,i)-1))
			{
				flag=0;
				break;
			}
		if(flag)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}