#include<stdio.h>
#include<vector>
using namespace std;
long n,d,i,sum,prm[50005],j,lst,st[50005];
bool bu[50005];
vector<long>vc[50005];
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<50001;i+=2)
		bu[i]=1;

	lst=0;
	prm[lst++]=2;
	for(i=3;i<50001;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<50001;j+=(2*i))
				bu[j]=1;
		}
	}

	for(i=0;i<lst;i++)
		for(j=prm[i];j<50001;j+=prm[i])
			vc[j].push_back(prm[i]);
	
	st[0]=0;
	for(i=1;i<50001;i++)
	{
		st[i]=2*i;
		n=1;
		for(j=0;j<vc[i].size();j++)
			st[i]/=vc[i][j],n*=(vc[i][j]-1);
		st[i]*=n;
		st[i]+=st[i-1];
	}

	while(~scanf("%ld",&n),n)
		printf("%ld\n",st[n]-1);
	return 0;
}