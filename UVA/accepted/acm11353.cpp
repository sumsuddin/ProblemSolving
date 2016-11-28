#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<long>vc;
bool bu[2000010];
long i,j,l,cs=1;
struct struc
{
	long sr,value;
}nd[2000010];

int cmp(const void *a,const void *b)
{
    if(((struc *)a)->sr==((struc *)b)->sr)
    return ((struc *)a)->value-((struc *)b)->value;
    else
    return ((struc *)a)->sr-((struc *)b)->sr;
}

int main()
{
	bu[0]=1;
	bu[1]=1;
	for(i=0;i<=2000001;i++)
		nd[i].value=i;

	for(i=4;i<2000001;i+=2)
		bu[i]=1;

	for(i=3;i<2000001;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<2000001;j+=2*i)
				bu[j]=1;
		}
	}

	vc.push_back(2);
	for(i=3;i<=2000000;i+=2)
		if(bu[i]==0)
			vc.push_back(i);
	l=vc.size();
	
	for(i=4;i<=2000000;i++)
		if(bu[i])
		{
			for(j=0;j<l;j++)
				if(i%vc[j]==0)
				{
					nd[i].sr=1+nd[i/vc[j]].sr;
					break;
				}
		}
	qsort(nd,i,sizeof(nd[0]),cmp);
	while(scanf("%ld",&i),i)
		printf("Case %ld: %ld\n",cs++,nd[i].value);
	return 0;
}
