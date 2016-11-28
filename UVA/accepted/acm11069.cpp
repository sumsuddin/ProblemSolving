#include<stdio.h>
///solved from rec solution...
long n,sum,i,fn[100];
int main()
{
	fn[1]=1;
	fn[2]=2;
	fn[3]=2;
	fn[4]=3;
	fn[5]=4;

	for(i=6;i<77;i++)
		fn[i]=fn[i-5]+fn[i-1];

	while(~scanf("%ld",&n))
		printf("%ld\n",fn[n]);
	return 0;
}
