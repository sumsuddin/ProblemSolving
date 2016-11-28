#include<stdio.h>
#include<math.h>
char st[1010];
long ex,dt,des,i,m,b,j;
int main()
{
	while(scanf("%ld",&b),b)
	{
		scanf("%s%ld",&st,&m);

		ex=m;
		i=des=0;
		while(ex)
		{
			des+=(ex%10)*(long)pow(b,i++);
			ex/=10;
		}

		ex=0;

		for(i=0;st[i];i++)
		{
			ex=ex*10+(st[i]-'0');
			if(ex>=m)
			{
				dt=j=0;
				while(ex)
				{
					dt+=(ex%10)*(long)pow(b,j++);
					ex/=10;
				}
				dt%=des;
				ex=j=0;

				while(dt)
				{
					ex+=(dt%b)*(long)pow(10,j++);
					dt/=b;
				}
			}
		}
		printf("%ld\n",ex);
	}
	return 0;
}