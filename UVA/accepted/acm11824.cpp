#include<stdio.h>
#include<math.h>

void swap(long int *a,long int *b)
{
	long int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{

	long int i,n,sum,j,k,st[50];

	scanf("%ld",&n);

	while(n--)
	{
		for(i=0;;i++)
		{
			scanf("%ld",&st[i]);
			if(st[i]==0)
				break;
		}
		for(j=0;j<i;j++)
		{
			for(k=j+1;k<i;k++)
				if(st[j]<st[k])
					swap(&st[j],&st[k]);
		}

		sum=0;
		for(j=1;j<=i;j++)
			sum+=(long int)pow(st[j-1],j);

		sum*=2;
		if(sum>5000000)
			printf("Too expensive\n");
		else
			printf("%ld\n",sum);
	}
	return 0;
}