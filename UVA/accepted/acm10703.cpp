#include<stdio.h>
long i,j,w,h,x1,x2,y1,y2,l,sum,mat[550][550],tan;
int main()
{
	while(~scanf("%ld%ld%ld",&w,&h,&l) && (w|| h||l))
	{
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
				mat[i][j]=0;

		for(i=0;i<l;i++)
		{
			scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);

			if(x1>x2)
			{
				sum=x1;
				x1=x2;
				x2=sum;
			}
			if(y1>y2)
			{
				sum=y1;
				y1=y2;
				y2=sum;
			}

			for(j=y1;j<=y2;j++)
				if(mat[j][x1]<x2-x1+1)
					mat[j][x1]=x2-x1+1;
		}
		sum=0;
		for(i=1;i<=h;i++)
		{
			tan=0;
			for(j=1;j<=w;j++)
			{
				if(tan<j+mat[i][j]-1)
					tan=j+mat[i][j]-1;
				if(tan<j)
					sum++;
			}
		}
		if(sum==0)
			printf("There is no empty spots.\n");
		else if(sum==1)
			printf("There is one empty spot.\n");
		else
			printf("There are %ld empty spots.\n",sum);
	}
	return 0;
}