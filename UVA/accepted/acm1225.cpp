#include<stdio.h>
long n,d,st[10005][12];
int main()
{
	for(n=1;n<10000;n++)
	{
		for(d=0;d<10;d++)
			st[n][d]=st[n-1][d];
		d=n;
		while(d)
		{
			st[n][d%10]++;
			d/=10;
		}
	}
	scanf("%ld",&d);
	while(d--)
	{
		scanf("%ld",&n);
		printf("%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",st[n][0],st[n][1],st[n][2],st[n][3],st[n][4],st[n][5],st[n][6],st[n][7],st[n][8],st[n][9]);
	}
	return 0;
}