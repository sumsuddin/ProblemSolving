#include<stdio.h>
long i,flag,m,n,bc,x,y,t,fl;
char st[100];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		st[n]=0;
		m--;
		for(i=0;i<n;i++)
		{
			if(n-i-1<=m)
				st[i]='1',m--;
			else
				st[i]='0';
		}
		puts(st);

		flag=1;
		while(flag)
		{
			m=0;
			flag=0;
			fl=0;
			for(i=n-1;i>=0;i--)
			{
				if(st[i]=='0' && m)
				{
					flag=1;
					st[i]='1';
					m--;
					for(i=i+1;i<n;i++)
						if(n-i==m)
							st[i]='1',m--;
						else
							st[i]='0';

					break;
				}
				else if(st[i]=='1')
					m++;
			}
			if(flag)
				puts(st);
		}
		if(t)
			printf("\n");
	}
	return 0;
}