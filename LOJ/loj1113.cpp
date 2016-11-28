#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

stack<long>bck,frd;
long lst,t,crnt,cs=1;
char st[100],str[105][100];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		printf("Case %ld:\n",cs++);
		strcpy(str[0],"http://www.lightoj.com/");
		lst=1;
		crnt=0;

		while(!bck.empty())
			bck.pop();
		while(!frd.empty())
			frd.pop();

		while(scanf("%s",st) && strcmp(st,"QUIT"))
		{
			if(strcmp(st,"VISIT")==0)
			{
				scanf("%s",st);
				while(!frd.empty())
					frd.pop();

				bck.push(crnt);
				crnt=lst;
				strcpy(str[lst++],st);
				printf("%s\n",str[crnt]);
				
			}
			else if(strcmp(st,"BACK")==0)
			{
				if(bck.empty())
				{
					printf("Ignored\n");
					continue;
				}
				frd.push(crnt);
				crnt=bck.top();
				bck.pop();
				printf("%s\n",str[crnt]);
			}
			else
			{
				if(frd.empty())
				{
					printf("Ignored\n");
					continue;
				}
				bck.push(crnt);
				crnt=frd.top();
				frd.pop();
				printf("%s\n",str[crnt]);
			}
		}
	}
	return 0;
}