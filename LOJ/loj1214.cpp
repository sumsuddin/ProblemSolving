#include<stdio.h>
#include<string.h>
long i,ex,cs=1,t,n;
char st[210];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%ld",st,&n);

		if(st[0]=='-')
			strcpy(st,st+1);
		if(n<0)
			n*=-1;

		ex=0;
		for(i=0;st[i];i++)
		{
			ex=ex*10+(st[i]-'0');
			ex%=n;
		}
		if(ex==0)
			printf("Case %ld: divisible\n",cs++);
		else
			printf("Case %ld: not divisible\n",cs++);
	}
	return 0;
}