#include<stdio.h>
long i,j,a[5],c,n;
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld%ld%ld",&a[0],&a[1],&a[2]);
		for(i=0;i<3;i++)
		{
			for(j=i+1;j<3;j++)
			{
				if(a[i]>a[j])
				{
					c=a[i];
					a[i]=a[j];
					a[j]=c;
				}
			}
		}
		if(a[0]+a[1]>a[2])
			printf("OK\n");
		else
			printf("Wrong!!\n");
	}
	return 0;
}
//190 537 11278 11687 11936 11945 11946 11947
//190 640 11909