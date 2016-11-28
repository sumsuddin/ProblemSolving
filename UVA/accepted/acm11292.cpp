#include<stdio.h>
#include<algorithm>
using namespace std;
long i,j,a[20050],b[1000050],n,m,sum;
bool flag;
int main()
{
	while(~scanf("%ld%ld",&n,&m) && (n|| m))
	{
		sum=0;
		flag=1;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		
		for(i=0;i<m;i++)
			scanf("%ld",&b[i]);
		if(m<n)
			flag=0;
		if(flag)
		{
			sort(a,a+n);
			sort(b,b+m);
			for(i=j=0;i<n && flag;i++,j++)
			{
				if(j>=m)
				{
					flag=0;
					break;
				}
				while(a[i]>b[j])
				{
					j++;
					if(j>=m)
					{
						flag=0;
						break;
					}
				}
				sum+=b[j];
			}
		}
		if(flag)
			printf("%ld\n",sum);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}