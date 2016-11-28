#include<stdio.h>
long i,j,n,a[100],flag,mx,cs=1,p;
bool bu[50000],cu[50000];
int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<30005;i++)
			bu[i]=cu[i]=0;
		bu[0]=1;
		mx=0;
		flag=1;
		scanf("%ld",&a[0]);
		p=a[0];
		if(a[0]<1)
			flag=0;
		bu[a[0]]=1;
		mx=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%ld",&a[i]);
			if(flag==0)
				continue;

			if(a[i]<=p)
				flag=0;
			else
				p=a[i];

			if(cu[a[i]])
				flag=0;
			if(flag)
			{
				for(j=mx;j>=0;j--)
					if(bu[j])
					{
						if(j)
							cu[j+a[i]]=1;

						bu[j+a[i]]=1;
						if(j+a[i]>mx)
							mx=j+a[i];
					}
			}
		}
		printf("Case #%ld:",cs++);
		for(i=0;i<n;i++)
			printf(" %ld",a[i]);
		printf("\n");
		if(flag)
			printf("This is an A-sequence.\n");
		else
			printf("This is not an A-sequence.\n");

	}
	return 0;
}
