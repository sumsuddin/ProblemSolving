#include<stdio.h>
#include<string.h>
long st[20],c,n;
char s[20];

int main()
{
	while(scanf("%ld",&n),n)
	{
		st[1]=1;st[2]=2;st[3]=3;

		while(n--)
		{
			scanf("%s",s);

			if(strcmp(s,"north")==0)
			{
				c=st[2];
				st[2]=st[1];
				st[1]=7-c;
			}
			else
				if(strcmp(s,"east")==0)
				{
					c=st[3];
					st[3]=7-st[1];
					st[1]=c;
				}
				else
					if(strcmp(s,"south")==0)
					{
						c=st[2];
						st[2]=7-st[1];
						st[1]=c;
					}
					else if(strcmp(s,"west")==0)
					{
						c=st[3];
						st[3]=st[1];
						st[1]=7-c;
					}
		}
		printf("%ld\n",st[1]);
	}
	return 0;
}