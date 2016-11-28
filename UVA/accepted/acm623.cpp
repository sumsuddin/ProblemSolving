#include<stdio.h>
#include<string.h>
int a[3000],i,j,l,p,k;
char st[1005][3000];
int main()
{
	strcpy(st[0],"1");
	strcpy(st[1],"1");
	for(k=2;k<1001;k++)
	{
		a[0]=l=1;
		for(i=2;i<=k;i++)
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
		}
		p=0;
		while(l--)
			st[k][p++]=a[l]+48;
		st[k][p]=0;
	}
	while(scanf("%d",&i)==1)
	{
		printf("%d!\n",i);
		puts(st[i]);
	}

	return 0;
}