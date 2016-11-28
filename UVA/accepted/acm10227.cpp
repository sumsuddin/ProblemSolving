#include<stdio.h>

long mat[110][110],vst[110],p,t,flag,T,i,j,k;
char st[110];

int main()
{
    scanf("%ld",&T);
    getchar();
    getchar();

    while(T--)
    {
        gets(st);
        sscanf(st,"%ld%ld",&p,&t);
        for(i=1;i<=p;i++)
        {
            vst[i]=1;
            for(j=1;j<=t;j++)
            mat[i][j]=0;
        }

        while(gets(st) && st[0])
        {
            sscanf(st,"%ld%ld",&i,&j);
            mat[i][j]=1;
        }

        for(i=1;i<=p;i++)
        for(j=i+1;j<=p;j++)
        {
            if(vst[j])
            {
                flag=1;
                for(k=1;k<=t;k++)
                if(mat[i][k]!=mat[j][k])
                flag=0;

                if(flag)
                vst[j]=0;
            }
        }
        t=0;
        for(i=1;i<=p;i++)
        t+=vst[i];
        printf("%ld\n",t);
        if(T)
        printf("\n");
    }
    return 0;
}
