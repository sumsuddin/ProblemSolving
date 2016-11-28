#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
int main()
{
	long a[7],n,i,j;
	scanf("%ld",&n);

	while(n--)
	{
		for(i=0;i<4;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<4;i++)
		{
			for(j=i+1;j<4;j++)
				if(a[i]>a[j])
					swap(a[i],a[j]);
		}
		if(a[0]==0 || (a[0]+a[1]+a[2]-a[3])<1)
			printf("banana\n");
		else
			if(a[0]==a[3])
				printf("square\n");
			else
				if(a[0]==a[1] && a[2]==a[3])
					printf("rectangle\n");
				else
					printf("quadrangle\n");
					
	}
	return 0;
}