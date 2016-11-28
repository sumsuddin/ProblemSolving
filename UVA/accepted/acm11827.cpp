#include<stdio.h>

long n,i,j,k,max,st[150],gc;
char c,b;

long gcd(long a,long b)
{
	while(1)
	{
		gc=b%a;
		if(gc==0)
			break;
		b=a;
		a=gc;
	}
	return a;
}

int main()
{
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		max=i=st[0]=0;b=1;
		while(1)
		{
			scanf("%c",&c);
			if(c==' ')
				b=' ';
			else if(c>47 && c<58)
			{
				if(b==' ')
				{
					b=1;
					i++;
					st[i]=0;
				}
				st[i]=st[i]*10+(c-'0');
			}
			else if(c=='\n')
				break;
		}

		for(j=0;j<=i;j++)
		{
			for(k=j+1;k<=i;k++)
			{
				gc=gcd(st[j],st[k]);
				if(gc>max)
					max=gc;
			}
		}
		printf("%ld\n",max);
	}
	return 0;
}