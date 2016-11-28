/*#include<stdio.h>
int main()
{
	printf("         6         8\n        35        49\n       204       288\n      1189      1681\n      6930      9800\n     40391     57121\n    235416    332928\n   1372105   1940449\n   7997214  11309768\n  46611179  65918161\n");

	return 0;
}*/

#include<stdio.h>
int main()
{
	long a[15],b[15],i=8;

	a[9]=6;b[9]=8;
	printf("%10ld%10ld\n",a[9],b[9]);
	a[8]=35;b[8]=49;	
	while(i--)
	{
		printf("%10ld%10ld\n",a[i+1],b[i+1]);
		a[i]=a[i+1]*6-a[i+2];
		b[i]=a[i]+a[i+1]+b[i+1];
	}
	printf("%10ld%10ld\n",a[0],b[0]);
	return 0;
}