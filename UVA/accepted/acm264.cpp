#include<stdio.h>

int main()
{
	long int a,i,j,n;

	while(scanf("%ld",&n)==1)
	{
		a=0;
		for(i=1;;i++)
		{
			for(j=1;j<=i;j++)
			{
				a++;
				if(a==n)
				{
					if(i%2)
						printf("TERM %ld IS %ld/%ld\n",a,i-j+1,j);
					else
						printf("TERM %ld IS %ld/%ld\n",a,j,i-j+1);
					break;
				}
			}
			if(a==n)
				break;
		}
	}
	return 0;
}