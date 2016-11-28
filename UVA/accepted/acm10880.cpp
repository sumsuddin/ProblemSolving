#include<stdio.h>
#include<math.h>
#include<set>
using namespace std;

long i,a,b,cs=1,sq,t;


int main()
{
	set<long> mst;

	set<long>::iterator it;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		if(a==b)
		{
			printf("Case #%ld: 0\n",cs++);
			continue;
		}

		a-=b;
		sq=sqrt(a);
		for(i=1;i<=sq;i++)
		{
			if(a%i==0)
			{
				if(i>b)
					mst.insert(i);
				if(a/i>b)
					mst.insert(a/i);
			}
		}
		printf("Case #%ld:",cs++);
		for(it=mst.begin();it!=mst.end();it++)
			printf(" %ld",*it);
		printf("\n");
		mst.clear();
	}
	return 0;
}