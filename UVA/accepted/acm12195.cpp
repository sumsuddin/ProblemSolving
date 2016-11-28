#include<stdio.h>
long sum,i;
double x,vl[100];
char st[500];
int main()
{
	vl['W']=1.0;
	vl['H']=0.5;
	vl['Q']=1.0/4.0;
	vl['E']=1.0/8.0;
	vl['S']=1.0/16.0;
	vl['T']=1.0/32.0;
	vl['X']=1.0/64.0;

	while(scanf("%s",st) && st[0]!='*')
	{
		x=0;
		sum=0;
		for(i=1;st[i];i++)
		{
			if(st[i]=='/')
			{
				if(x==1.0)
					sum++;
				x=0.0;
			}
			else
				x+=vl[st[i]];
		}
		printf("%ld\n",sum);
	}
	return 0;
}