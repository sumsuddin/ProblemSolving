#include<stdio.h>

long i,wt[5010],t,m,n,j;
bool flag;

int main()
{
	struct
	{
		long st,end,wt;
	}nd[5010];

	scanf("%ld",&t);
	while(t--)
	{
		flag=1;
		scanf("%ld%ld",&n,&m);

		for(i=1;i<n;i++)
			wt[i]=9999999;
		wt[0]=0;

		for(i=0;i<m;i++)
			scanf("%ld%ld%ld",&nd[i].st,&nd[i].end,&nd[i].wt);

		for(j=0;j<n-1;j++)
		{
			for(i=0;i<m;i++)
			{
				if(wt[nd[i].end]>(wt[nd[i].st]+nd[i].wt))
					wt[nd[i].end]=(wt[nd[i].st]+nd[i].wt);
			}
		}
		for(i=0;i<m;i++)
		{

			if(wt[nd[i].end]>(wt[nd[i].st]+nd[i].wt))
			{
				flag=0;
				break;
			}
		}

		if(flag==0)
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}