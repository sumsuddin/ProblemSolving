#include<stdio.h>
#include<math.h>
long i,j,k,mat[15][15],chk[100],n,all,t,sl;
bool flag;
void backtrk(long vst,long ud,long ld,long sum,long col)
{
	long k;
	if(vst==255)
	{
		chk[all++]=sum;
		return;
	}

	for(k=0;k<8;k++)
	{
		if((ud>>k & 1)==0  && (vst>>k & 1)==0 && (ld>>k & 1)==0)
		{
			backtrk((vst | 1<<k),(ud | 1<<k)>>1,(ld | 1<<k)<<1,sum*10+mat[k][col],col+1);
		}
	}
}

int main()
{
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			mat[i][j]=i+1;

	all=0;

	backtrk(0,0,0,0,0);

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		if(flag)
			printf("\n");
		else
			flag=1;

		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		sl=1;
		for(i=0;i<all;i++)
		{
			if((chk[i]/(long)pow(10,(8-k)))%10==n)
			{
				printf("%2ld     ",sl++);
				for(j=1;j<=8;j++)
					printf(" %ld",(chk[i]/(long)pow(10,(8-j)))%10);
				printf("\n");
			}
		}
	}
	return 0;
}