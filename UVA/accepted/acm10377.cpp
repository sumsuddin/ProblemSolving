#include<stdio.h>
long i,t,dir,x,y,sc,sr;
char c,st[100][100];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&sr,&sc);
		getchar();

		for(i=0;i<sr;i++)
			gets(st[i]);

		scanf("%ld%ld",&x,&y);
		x--;y--;
		getchar();
		dir=0;

		while(scanf("%c",&c) && c!='Q')
		{
			if(c=='R')
			{
				(++dir%=4);
			}
			else if(c=='L')
			{
				dir--;
				if(dir<0)
					dir=3;
			}
			else if(c=='F')
			{
				if(dir==0)
				{
					if(st[x-1][y]==' ')
					{
						x--;
						if(x<=0)
							x=0;
					}
				}
				else if(dir==1)
				{
					if(st[x][y+1]==' ' && y<sc-1)
						y++;
				}
				else if(dir==2)
				{
					if(st[x+1][y]==' ' && x<sr-1)
						x++;
				}
				else
				{
					if(st[x][y-1]==' ')
					{
						y--;
						if(y<=0)
							y=0;
					}
				}
			}
		}
		printf("%ld %ld ",x+1,y+1);
		if(dir==0)
			printf("N\n");
		else if(dir==1)
			printf("E\n");
		else if(dir==2)
			printf("S\n");
		else 
			printf("W\n");
		if(t)
			printf("\n");
	}
	return 0;
}