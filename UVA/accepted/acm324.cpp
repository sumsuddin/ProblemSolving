#include<stdio.h>
#include<string.h>
int a[800],i,j,l,p,k,pa[60];
char st[370][800];
int main()
{
	strcpy(st[0],"1");
	strcpy(st[1],"1");
	for(k=2;k<367;k++)
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
		for(j=48;j<59;j++)
			pa[j]=0;
		printf("%d! --\n",i);
		
		for(j=0;st[i][j];j++)
			pa[st[i][j]]++;
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",pa[48],pa[49],pa[50],pa[51],pa[52],pa[53],pa[54],pa[55],pa[56],pa[57],pa[58]);
	}

	return 0;
}
