#include<stdio.h>

void f91(long int *a)
{
	*a+=11;
	if(*a>100)
	{
		*a-=10;
		if(*a>100)
			*a-=10;
		else
			f91(a);
	}
	else
		f91(a);
}

int main()
{
	long int a,n;
	while(scanf("%ld",&n),n)
	{
		a=n;
		if(n>100)
			n-=10;
		else
			f91(&n);
		printf("f91(%ld) = %ld\n",a,n);
	}
	return 0;
}
/*#include<stdio.h>

int main()
{
	long int a,n;
	while(scanf("%ld",&n),n)
	{
		a=n;
		if(n>100)
			n-=10;
		else
		{
f91:
			n+=11;
			if(n>100)
			{
				n-=10;
				if(n>100)
					n-=10;
				else
					goto f91;
			}
			else
				goto f91;
		}
		printf("f91(%ld) = %ld\n",a,n);
	}
	return 0;
}
*/