#include<stdio.h>
long su[10005],si[10005],c,st[10005],i,j;
int main()
{
	for(i=59;i>0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			c=i*i*i-j*j*j;
			
			if(c<10001)
			{
				st[c]=1;
				if(su[c]>i || su[c]==0)
				{
					su[c]=i;
					si[c]=j;
				}
			}
			else
				break;
		}
	}
	while(scanf("%ld",&c) &&  c)
	{
		if(st[c])
			printf("%ld %ld\n",su[c],si[c]);
		else
			printf("No solution\n");
	}

	return 0;
}