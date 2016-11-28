#include<stdio.h>

int h[]={0,0,0,1,-1},v[]={0,1,-1,0,0},x[300],y[300],i,j,p,q,cs=1;
char st[300],mat[5][5];

int main()
{
	x['a']=0;y['a']=0;
	x['b']=0;y['b']=1;
	x['c']=0;y['c']=2;
	x['d']=1;y['d']=0;
	x['e']=1;y['e']=1;
	x['f']=1;y['f']=2;
	x['g']=2;y['g']=0;
	x['h']=2;y['h']=1;
	x['i']=2;y['i']=2;


	while(gets(st))
	{
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				mat[i][j]='0';

		for(i=0;st[i];i++)
		{
			for(j=0;j<5;j++)
			{
				p=x[st[i]]-h[j];
				q=y[st[i]]-v[j];
				if(p>=0 && p<3 && q>=0 && q<3)
				{
					mat[p][q]++;
					if(mat[p][q]>'9')
						mat[p][q]='0';
				}
			}
		}
		printf("Case #%ld:\n",cs++);

		for(i=0;i<3;i++)
		{
			printf("%c",mat[i][0]);
			for(j=1;j<3;j++)
				printf(" %c",mat[i][j]);
			printf("\n");
		}
	}
	return 0;
}