#include<stdio.h>
#include<algorithm>
using namespace std;
long i,n,m,sum,st[5000010];
bool sc[5000010];
int c;
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&m);
		for(i=0;i<m;i++)
		{
			scanf("%ld",&st[i]);
			if(st[i]<0)
			{
				st[i]*=-1;
				sc[st[i]]=0;
			}
			else
				sc[st[i]]=1;
		}
		sum=0;c=5;
		sort(st,st+m);
		for(i=0;i<m;i++)
		{
			if(c != (int)sc[st[i]])
				sum++;
			c=sc[st[i]];
		}
		printf("%ld\n",sum);
	}
	return 0;
}