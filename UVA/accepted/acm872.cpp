#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

vector<long>vc[100];
char st[1000],sy[1000],c,d;
long i,ind[1000],indeg[1000],t,ll;
bool flag=1,tru;

void call(long n,long now)
{
    long i,j;
    bool flag=1;
    st[now]=0;
    for(i=0;i<26;i++)
    {
        if(ind[i] && ((n>>i) & 1)==0 && indeg[i]==0)
        {
            for(j=0;j<vc[i].size();j++)
            indeg[vc[i][j]]--;
            st[now]=i+'A';
            flag=0;
            call(n | (1<<i),now+1);
            for(j=0;j<vc[i].size();j++)
            indeg[vc[i][j]]++;
        }
    }
    if(flag && strlen(st)==ll)
    {
        tru=0;
        printf("%c",st[0]);
        for(i=1;st[i];i++)
        printf(" %c",st[i]);
        printf("\n");
    }
}

int main()
{
    scanf("%ld",&t);
    getchar();
    while(t--)
    {
        tru=1;
        getchar();
        gets(st);

        ll=(strlen(st)+1)/2;
        for(i=0;i<26;i++)
        {
            vc[i].clear();
            ind[i]=indeg[i]=0;
        }

        for(i=0;st[i];i+=2)
        ind[st[i]-'A']=1,st[i]=0;

        gets(sy);

        if(flag)
        flag=0;
        else
        printf("\n");
        for(i=0;i<strlen(sy);i+=4)
        {
            sscanf(sy+i,"%c<%c",&c,&d);
            vc[c-'A'].push_back(d-'A');
            indeg[d-'A']++;
        }
        call(0,0);
        if(tru)
        printf("NO\n");
    }
    return 0;
}
