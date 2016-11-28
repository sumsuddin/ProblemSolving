#include<stdio.h>
#include<stack>
using namespace std;

stack<char>stk;
char st[10050];
long i,cs=1,ind[1050],t;
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        for(i=0;i<100;i++)
        ind[i]=0;

        scanf("%s",&st);
        stk.push(st[0]);

        for(i=1;st[i];i++)
        {
            if(st[i]!=stk.top())
            {
                ind[stk.top()]++;
                stk.push(st[i]);
                ind[stk.top()]++;
            }
            else
                stk.pop();
        }
        while(!stk.empty())
        stk.pop();
        printf("Case %ld\n",cs++);
        for(i='A';i<='Z';i++)
        if(ind[i])
        printf("%c = %ld\n",(char)i,ind[i]);
    }
    return 0;
}
