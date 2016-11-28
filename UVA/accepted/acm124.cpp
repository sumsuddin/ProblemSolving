#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

vector<long>vc[100];
char st[1000],sy[1000],c,d;
long i,ind[1000],indeg[1000];
bool flag=1;

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
            st[now]=i+'a';
            flag=0;
            call(n | (1<<i),now+1);
            for(j=0;j<vc[i].size();j++)
            indeg[vc[i][j]]++;
        }
    }
    if(flag)
    puts(st);
}

int main()
{
    while(gets(st))
    {
        for(i=0;i<26;i++)
        {
            vc[i].clear();
            ind[i]=indeg[i]=0;
        }

        for(i=0;st[i];i++)
        ind[st[i]-'a']=1,st[i]=0;

        gets(sy);

        if(flag)
        flag=0;
        else
        printf("\n");
        for(i=0;i<strlen(sy);i+=4)
        {
            sscanf(sy+i,"%c %c",&c,&d);
            vc[c-'a'].push_back(d-'a');
            indeg[d-'a']++;
        }
        call(0,0);
    }
    return 0;
}
