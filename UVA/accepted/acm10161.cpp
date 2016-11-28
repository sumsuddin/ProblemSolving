#include<stdio.h>
long i,n,p,t,x,y;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		if(n==1)
			printf("1 1\n");
		else
		{
			p=1;
			for(i=0;n>p;i++)
				p=(i*(i+1))+1;
			i--;

			if(i%2)
			{
				t=p-n;
				if(t<=i)
				{
					x=i-t+1;
					y=i+1;
				}
				else
				{
					p=(i*(i-1))+1;
					x=i-n+p;
					y=i;
				}
			}
			else
			{
				t=p-n;
				if(t<=i)
				{
					y=i-t+1;
					x=i+1;
				}
				else
				{
					p=(i*(i-1))+1;
					y=i-n+p;
					x=i;
				}
			}
			printf("%ld %ld\n",x,y);
		}
	}
	return 0;
}
/*#include<stdio.h>
long i,j,x,y,h;
int t[2000000005][5];
int main()
{
	h=1;
	x=0;
	y=1;

	for(i=2;h<2000;i++)
	{
		for(j=i;j>=1;j--)
		{
			t[++h][y]=i;
			t[h][x]=i-j+1;
		}
		for(j=1;j<i;j++)
		{
			t[++h][x]=i;
			t[h][y]=i-j;
		}
		x=(x+1)%2;
		y=(y+1)%2;
	}

	while(scanf("%ld",&i)==1)
	{
		printf("%d %d\n",t[i][0],t[i][1]);
	}

	return 0;
}*/