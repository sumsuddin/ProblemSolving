#include<stdio.h>
#include<string.h>
int a[100000],i,j,l,p;
char b[10005];
int main()
{
	b[0]=1;
	b[1]=1;

	a[0]=l=1;
	for(i=2;i<=10001;i++)
	{
		p=0;
		for(j=0;j<l;j++)
			a[j]*=i;

		for(j=0;j<l;j++)
		{
			if(a[j]/10)
			{
				if(j<l-1)
					a[j+1]+=a[j]/10;
				else
				{
					a[j+1]=a[j]/10;
					p++;
				}
			}
			a[j]=a[j]%10;
		}
		l+=p;
		if((p=a[l-1])>9)
		{
			l--;
			while(p)
			{
				a[l++]=p%10;
				p/=10;
			}
		}
	p=0;
	while(a[p++]==0);
	b[i]=a[p-1];
	}


	while(scanf("%d",&i)==1)
		printf("%5d -> %d\n",i,b[i]);

	return 0;
}