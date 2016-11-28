#include<stdio.h>
long i,j,k,st[50010][5],x;
int main()
{
	for(i=0;i<50001;i++)
		st[i][0]=-1;

	for(i=224;i>=0;i--)
	{
		for(j=224;j>=0;j--)
		{
			for(k=224;k>=0;k--)
			{
				x=i*i+j*j+k*k;
				if(x<50001)
				{
					st[x][0]=i;
					st[x][1]=j;
					st[x][2]=k;
				}
			}
		}
	}
	scanf("%ld",&x);
	while(x--)
	{
		scanf("%ld",&i);
		if(st[i][0]==-1)
			printf("-1\n");
		else
			printf("%ld %ld %ld\n",st[i][0],st[i][1],st[i][2]);
	}
	return 0;
}