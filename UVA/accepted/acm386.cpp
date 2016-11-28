#include<stdio.h>
#include<math.h>
long i,j,k,x,y,st[210][210][20],tr[210];

int main()
{
	for(i=2;i<201;i++)
	{
		for(j=i+1;j<201;j++)
		{
			for(k=j+1;k<201;k++)
			{
				x=i*i*i+j*j*j+k*k*k;
				y=(long)(pow(x,(1.0/3.0))+.0000001);
				if( y<201 && y*y*y==x)
				{
					st[tr[y]][y][0]=i;
					st[tr[y]][y][1]=j;
					st[tr[y]][y][2]=k;
					tr[y]++;
				}
			}
		}
	}
	for(i=6;i<201;i++)
		if(st[0][i][0])
		{
			for(j=0;j<tr[i];j++)
				printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n",i,st[j][i][0],st[j][i][1],st[j][i][2]);
		}
	return 0;
}