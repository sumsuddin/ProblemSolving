#include<stdio.h>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
long t,m,ind[100050],sum,i,lst,q,cs=1;
char st[100],sy[100];
queue<long>que;
vector<long>vc[100050];
map <string,long>mp;
int main()
{
    scanf("%ld",&t);
    
    while(t--)
    {
              scanf("%ld",&m);
              lst=1;
              for(i=0;i<=2*m;i++)
              ind[i]=0;
              for(i=0;i<m;i++)
              {
                              scanf("%s%s",st,sy);
                              
                              if(mp[st]==0)
                              mp[st]=lst++;
                              if(mp[sy]==0)
                              mp[sy]=lst++;
                              ind[mp[sy]]++;
                              vc[mp[st]].push_back(mp[sy]);
              }
              sum=0;
              for(i=1;i<lst;i++)
              if(ind[i]==0)
              que.push(i),sum++;
              
              while(!que.empty())
              {
                    q=que.front();
                    que.pop();
                    for(i=0;i<vc[q].size();i++)
                    {
                          ind[vc[q][i]]--;
                          if(ind[vc[q][i]]==0)
                          que.push(vc[q][i]),sum++;
                    }
              }
              if(sum==lst-1)
              printf("Case %ld: Yes\n",cs++);
              else
              printf("Case %ld: No\n",cs++);
              mp.clear();
              for(i=0;i<lst;i++)
              vc[i].clear();
    }
    return 0;
}
