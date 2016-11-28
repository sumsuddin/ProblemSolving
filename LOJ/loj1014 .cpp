#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<long>vc;
long i,a,b,cs=1,sq,t;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&a,&b);

		a-=b;

		sq=sqrt(a);

		for(i=1;i<=sq;i++)
		{
			if(a%i==0 && i>b)
				vc.push_back(i);
			if(a%i==0 && (a/i)>b && i!=a/i)
				vc.push_back(a/i);
		}
		if(vc.size()==0)
			printf("Case %ld: impossible\n",cs++);
		else
		{
			printf("Case %ld:",cs++);
			sort(vc.begin(),vc.end());
			for(i=0;i<vc.size();i++)
				printf(" %ld",vc[i]);
			printf("\n");
		}
		vc.clear();
	}
	return 0;
}