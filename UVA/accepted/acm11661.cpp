#include<stdio.h>
#include<string.h>
long n,i,d,r,min,j;
char c;
bool flag;
int main()
{
	while(scanf("%ld",&n),n)
	{
		getchar();
		d=r=flag=0;
		min=2000009;
		for(i=0;i<n;i++)
		{
			scanf("%c",&c);
			if(flag)
				continue;

			if(c=='R')
			{
				if(d)
					if(min>j)
						min=j;
				r=1;
				d=0;
				j=0;
			}
			else if(c=='D')
			{
				if(r)
					if(min>j)
						min=j;
				r=0;
				d=1;
				j=0;
			}
			else
				if(c=='Z')
				{
					min=-1;
					flag=1;
				}
				else
					j++;
		}
		printf("%ld\n",min+1);
	}

	return 0;
}
