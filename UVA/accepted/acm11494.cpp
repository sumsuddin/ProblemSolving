#include<stdio.h>
int main()
{
    long a,b,c,d;
	while(scanf("%ld%ld%ld%ld",&a,&b,&c,&d) && a && b && c && d)
	{
		if(a==c && b==d)
			printf("0\n");
		else
			if(a==c || b==d || (a-c)==(b-d) || (a-c)==-1*(b-d))
				printf("1\n");
			else
				printf("2\n");
	}
	return 0;
}
