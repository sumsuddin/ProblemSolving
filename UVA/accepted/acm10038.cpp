#include<stdio.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	long a[10000],d[10000],n,i,j,p;
	while(scanf("%ld",&n)==1)
	{
		p=1;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<n;i++)
			d[i]=abs(a[i]-a[i-1]);
		for(i=1;i<n;i++)
			for(j=i+1;j<n;j++)
				if(d[i]>d[j])
					swap(d[i],d[j]);
		for(i=1;i<n;i++)
			if(d[i]!=i)
			{
				printf("Not jolly\n");
				p=0;
				break;
			}

		if(p)
			printf("Jolly\n");
	}
	return 0;
}