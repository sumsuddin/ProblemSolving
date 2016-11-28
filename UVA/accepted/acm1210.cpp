#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc;
bool bu[10050];
long l,i,j,k,st[10050],sr[10050];
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<10010;i+=2)
		bu[i]=1;

	for(i=3;i<10010;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<10010;j+=i)
				bu[j]=1;
		}
	}
	for(i=2;i<10010;i++)
		if(bu[i]==0)
			vc.push_back(i);
	j=vc.size();
	st[0]=0;
	for(i=1;i<j;i++)
		st[i]+=st[i-1]+vc[i-1];

	for(i=0;i<j;i++)
		for(k=0;k<i;k++)
		{
			l=st[i]-st[k];
			if(l<10001 && l>1)
			sr[l]++;
		}

	while(scanf("%ld",&i),i)
	{
		printf("%ld\n",sr[i]);
	}
	return 0;
}