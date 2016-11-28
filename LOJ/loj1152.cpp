#include<stdio.h>
long lst,i,j,mat[500][500],vst[500],ind[500][500],t,r,c,k,h[]={0,0,1,-1},v[]={1,-1,0,0},x,y,flag,cs=1;
char st[1000][1000];

long dfs(long p,long mx)
{
    if(p==lst)
    {
        flag=0;
        return mx;
    }

    vst[p]=0;
    long i,del=0;
    for(i=0;i<=lst && flag;i++)
    {
        if(flag && vst[i] && mat[p][i]>0)
        {
            del=dfs(i,mx<mat[p][i]?mx:mat[p][i]);
            mat[p][i]-=del;
            mat[i][p]+=del;
        }
    }

    vst[p]=1;
    return del;
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&r,&c);
        lst=1;

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            ind[i][j]=lst++;

            scanf("%s",st[i]);
        }

        for(i=0;i<=lst;i++)
        {
            vst[i]=1;
            for(j=0;j<=lst;j++)
            mat[i][j]=0;
        }


        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            if(st[i][j]=='*')
            {
                for(k=0;k<4 && (i+j)%2==0;k++)
                {
                    x=i+h[k];
                    y=j+v[k];

                    if(x>=0 && x<r && y>=0 && y<c && st[x][y]=='*')
                    mat[ind[i][j]][ind[x][y]]=1;
                }
                if((i+j)%2)
                mat[ind[i][j]][lst]=1;
                else
                mat[0][ind[i][j]]=1;
            }
        }

        vst[0]=vst[lst]=1;
        x=0;
        flag=1;
        while(dfs(0,1000000000))
        x++,flag=1;

        for(i=0;i<lst;i++)
        x+=mat[0][i]+mat[i][lst];
        printf("Case %ld: %ld\n",cs++,x);
    }
    return 0;
}
