#include<stdio.h>

int main()
{
	int a,b,c[65536],e,i,j,k,l,ans;
	
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		ans=0;
		scanf("%d",&b);

		for(j=0;j<b;j++)
			scanf("%d",&c[j]);


		for(k=0;k<b;k++)
			for(l=k+1;l<b;l++)
			{
				if(c[k]>c[l])
				{
					e=c[k];
					c[k]=c[l];
					c[l]=e;
					ans++;
				}
			}

			printf("Optimal train swapping takes %d swaps.\n",ans);
	}

return 0;

}
