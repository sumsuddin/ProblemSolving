#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long i,j,r,c,mat[1005][1005],a,b,t;
bool vst[1005][1005];
char *pch,st[1000];
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&r,&c);
		getchar();

		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				vst[i][j]=1,mat[i][j]=0;

        for(i=1; i<=r; i++)
        {
            gets(st);
            pch=strtok(st," ");
            a=atol(pch);
            pch=strtok(NULL," ");
            while(pch!=NULL)
            {
                b=atol(pch);
                vst[a][b]=0;
                pch=strtok(NULL," ");
            }
        }
		mat[1][1]=1;
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				if(vst[i][j] && (i>1 || j>1))
					mat[i][j]=mat[i-1][j]+mat[i][j-1];
					
		printf("%lld\n",mat[r][c]);
		if(t)
			printf("\n");
	}
	return 0;
}
