#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
int i,n,st[30];
bool flag;
int main()
{
	scanf("%d",&n);
	printf("Lumberjacks:\n");
	while(n--)
	{
		for(i=0;i<10;i++)
			scanf("%ld",&st[i]);

		flag=1;
		for(i=0;i<9;i++)
		{
			if(st[i+1]>st[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("Ordered\n");
			continue;
		}
		flag=1;
		for(i=0;i<9;i++)
		{
			if(st[i+1]<st[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("Ordered\n");
			continue;
		}
		flag=1;
		for(i=0;i<10;i+=2)
		{
			if(st[i+2]>st[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		for(i=1;i<10;i+=2)
		{
			if(st[i+2]<st[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("Ordered\n");
			continue;
		}
		flag=1;
		for(i=0;i<10;i+=2)
		{
			if(st[i+2]<st[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		for(i=1;i<10;i+=2)
		{
			if(st[i+2]>st[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	return 0;
}