#include<stdio.h>
long ind[1000],i,ans,t;
char st[2000000];
long min(long a,long b)
{
    return a<b?a:b;
}
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        for(i='A';i<='Z';i++)
        ind[i]=0;

        scanf("%s",&st);
        for(i=0;st[i];i++)
        ind[st[i]]++;

        ans=ind['M'];
        ans=min(ind['A']/3,ans);
        ans=min(ans,ind['R']/2);
        ans=min(ans,ind['G']);
        ans=min(ans,ind['I']);
        ans=min(ans,ind['T']);

        printf("%ld\n",ans);
    }
    return 0;
}
