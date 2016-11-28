#include<stdio.h>
#include<string.h>

long i,n,m,p;
char c,st[10005];
double sum,ch[300];

int main()
{
	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		memset(ch,0,sizeof(ch));

		gets(st);
		sscanf(st,"%ld",&m);

		sum=0;
		while(m--)
		{
			gets(st);
			sscanf(st,"%c %ld",&c,&p);

			ch[c]=p;
		}

		gets(st);
		sscanf(st,"%ld",&m);
		while(m--)
		{
			gets(st);
			for(i=0;st[i];i++)
				sum+=(ch[st[i]]/100);
		}
		printf("%.2lf$\n",sum);
	}
	return 0;
}