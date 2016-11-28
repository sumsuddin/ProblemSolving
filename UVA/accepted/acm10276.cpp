#include<stdio.h>
#include<math.h>
long i,j,test,p,st[100],sy[100],m,n;
bool flag;
int main()
{
	p=1;
	for(i=1;i<51;i++)
	{
		flag=1;
		while(flag)
		{
			flag=0;
			for(j=1;j<=i;j++)
			{
				if(st[j])
				{
					test=(long)sqrt(p+st[j]);
					if(test*test==p+st[j])
					{
						st[j]=p++;
						flag=1;
					}
				}
				else
				{
					flag=1;
					st[j]=p++;
				}
			}	
		}
		sy[i]=p-1;
	}

	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&m);
		printf("%ld\n",sy[m]);
	}
	return 0;
}