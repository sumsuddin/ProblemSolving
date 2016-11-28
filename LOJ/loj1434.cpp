#include<stdio.h>
#include<string.h>
long v[]={-1,-1,-1,0,0,0,1,1,1},h[]={-1,0,1,-1,0,1,-1,0,1};
char st[50][50],tan[50],str[20][20]={"UL","L","DL","U","*","D","UR","R","DR"};
long i,j,k,t,m,r,c,l,path[100],cs=1;
bool flag,vis[50][50][50];
void call(long x,long y,long len)
{
    if(flag)
        return;
    if(len==l)
    {
        flag=1;
        return;
    }
    vis[x][y][len-1]=0;
     
    for(long i=0;i<9;i++)
    {
        long p,q;
        p=x+h[i];
        q=y+v[i];
        
        if(flag || p>=r|| p<0 || q<0 || q>=c || vis[p][q][len]==0)
            continue;
        if(st[p][q]==tan[len])
            path[len]=i,call(p,q,len+1);
    }
}

int main()
{
    scanf("%ld",&t);
    
    while(t--)
    {
        scanf("%ld%ld",&r,&c);
        
        for(i=0;i<r;i++)
            scanf("%s",&st[i]);
        scanf("%ld",&m);
        printf("Case %ld:\n",cs++);
        while(m--)
        {
            scanf("%s",tan);
            l=strlen(tan);
            flag=0;
            for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            for(k=0;k<l;k++)
            vis[i][j][k]=1;
            
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(st[i][j]==tan[0])
                        call(i,j,1);
                    if(flag)
                    break;
                }
                if(flag)
                break;
            }
            if(flag)
            {
                printf("%s found: (%ld,%ld)",tan,i+1,j+1);
                for(i=1;i<l;i++)
                    printf(", %s",str[path[i]]);
                printf("\n");
            }
            else
                printf("%s not found\n",tan);
        }
    }
    return 0;
}
