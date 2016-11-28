#include<stdio.h>
#include<string.h>
long sum,mx,ans,fl,i;
char st[1000050];
int main()
{
	while(gets(st))
	{
		sum=0;
		for(i=0;st[i];i++)
			if(st[i]==' ')
				sum++;
			else
			{
				if(sum>mx)
					mx=sum;
				sum=0;
			}
		sum=0;
		while(mx>1)
		{
			if(mx%2)
				fl=1;
			else
				fl=0;
			mx>>=1,sum++;
			mx+=fl;
		}
		printf("%ld\n",sum);
	}
	return 0;
}