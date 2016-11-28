#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;
map<string,long >mp;
string str;
map<string ,long>::iterator it;
char st[10050],ss[500];
long n,ind,i;
bool flag,prnt;
int main()
{
    while(~scanf("%ld",&n))
    {
        while(gets(st) && strcmp(st,"EndOfText"))
        {
            ind=0;
            for(i=0;st[i];i++)
            {
                if(st[i]>='A' && st[i]<='Z')
                    st[i]+=32;
                if(st[i]>='a' && st[i]<='z')
                    ss[ind++]=st[i];
                else if(ind)
				{
					ss[ind]=0,ind=0;
					mp[ss]+=1;
				}
            }
			if(ind)
			{
				ss[ind]=0,ind=0;
				mp[ss]+=1;
			}
        }
        if(flag)
                printf("\n");
        else
            flag=1;
        prnt=1;
        for(it=mp.begin();it!=mp.end();it++)
        {
            i=it->second;
			str=it->first;
            if(it->second==n)
                cout<<str<<"\n",prnt=0;
        }
        if(prnt)
                printf("There is no such word.\n");
		mp.clear();
    }
    return 0;
}
