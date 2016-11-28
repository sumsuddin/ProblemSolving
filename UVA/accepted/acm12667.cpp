#include<stdio.h>
long n,i,t,m,j,ind[1000][1000],team,tim,mx[1000],solver[100];
char pr[100],vr[100];
int main()
{
    while(~scanf("%ld%ld%ld",&n,&t,&m))
    {
        for(i=1;i<=t;i++)
        for(j='A';j<'A'+n;j++)
        ind[i][j]=1;

        for(i='A';i<'A'+n;i++)
        mx[i]=0,solver[i]=-1;;

        while(m--)
        {
            scanf("%ld%ld%s%s",&tim,&team,&pr,&vr);

            if(vr[0]=='Y' && ind[team][pr[0]])
            {
                ind[team][pr[0]]=0;
                if(mx[pr[0]]<=tim)
                mx[pr[0]]=tim,solver[pr[0]]=team;
            }
        }
        for(i='A';i<'A'+n;i++)
        if(solver[i]==-1)
        printf("%c - -\n",(char)i);
        else
        printf("%c %ld %ld\n",(char)i,mx[i],solver[i]);
    }
    return 0;
}
