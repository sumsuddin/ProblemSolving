#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
using namespace std;
map<string,long>mp;
long t,g,cs=1;
double per[1000],p,sum;
char st[100];
int main()
{
	while(~scanf("%ld%ld",&t,&g))
	{
		cs=1;
		while(t--)
		{
			scanf("%s%lf",&st,&per[t]);
			mp[st]=t;
		}

		while(g--)
		{
			scanf("%s",st);
			sum=per[mp[st]]*10;

			while(scanf("%s",st) && st[0]=='+')
			{
				scanf("%s",st);
				sum+=per[mp[st]]*10;
			}
			scanf("%lf",&p);
			p*=10;
			if(strcmp(st,"=")==0)
			{
				if(sum==p)
					printf("Guess #%ld was correct.\n",cs++);
				else
					printf("Guess #%ld was incorrect.\n",cs++);
			}
			else if(strcmp(st,">=")==0)
			{
				if(sum>=p)
					printf("Guess #%ld was correct.\n",cs++);
				else
					printf("Guess #%ld was incorrect.\n",cs++);
			}
			else if(strcmp(st,"<=")==0)
			{
				if(sum<=p)
					printf("Guess #%ld was correct.\n",cs++);
				else
					printf("Guess #%ld was incorrect.\n",cs++);
			}
			else if(strcmp(st,">")==0)
			{
				if(sum>p)
					printf("Guess #%ld was correct.\n",cs++);
				else
					printf("Guess #%ld was incorrect.\n",cs++);
			}
			else if(strcmp(st,"<")==0)
			{
				if(sum<p)
					printf("Guess #%ld was correct.\n",cs++);
				else
					printf("Guess #%ld was incorrect.\n",cs++);
			}
		}
		mp.clear();
	}
	return 0;
}