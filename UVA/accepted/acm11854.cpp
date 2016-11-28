#include<stdio.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	long a,b,c;

	while(scanf("%ld%ld%ld",&a,&b,&c) && (a||b||c))
	{
		if(a>b)
			swap(a,b);
		if(a>c)
			swap(a,c);
		if(b>c)
			swap(b,c);

		if((a*a+b*b)==c*c)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}