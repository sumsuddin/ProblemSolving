#include<stdio.h>
long i,j,n,m,fib[100],st[500],d,max;
char c,sy[500],sr[500];
bool flag;
int main()
{
	fib[1]=1;
	fib[2]=2;
	for(i=3;i<45;i++)
		fib[i]=fib[i-2]+fib[i-1];

	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&m);
		max=0;
		for(i=0;i<m;i++)
		{
			scanf("%ld",&st[i]);
			if(max<st[i])
				max=st[i];
		}

		getchar();
		i=0;
		while(scanf("%c",&c) && c!='\n')
		{
			if(c>64 && c<91)
			{
				sy[i++]=c;
			}
		}
		d=0;
		for(i=1;fib[i]<=max;i++)
		{
			flag=1;
			for(j=0;j<m;j++)
			{
				if(fib[i]==st[j])
				{
					sr[d++]=sy[j];
					flag=0;
					break;
				}
			}
			if(flag)
				sr[d++]=' ';
		}
		sr[d]=0;
		puts(sr);
	}
	return 0;
}