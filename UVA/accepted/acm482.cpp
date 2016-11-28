#include<stdio.h>
long i,n,st[1005],p;
char c,sy[1005][50];
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		i=0;
		while(scanf("%ld%c",&st[i++],&c) && c!='\n')
			;
		p=i;
		for(i=0;i<p;i++)
			scanf("%s",sy[st[i]]);
		for(i=1;i<=p;i++)
			puts(sy[i]);
		if(n)
			printf("\n");
	}
	return 0;
}