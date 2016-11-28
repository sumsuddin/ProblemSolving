#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[10];
long par[10][10],i,j,sum;
bool mat[10][10];
void prn(long p,long st)
{
	if(st)
	{
		prn(par[st-1][p],st-1);
		printf("%ld",p);
	}
	else
		printf("%ld",p);
}


void rec(long p,long st)
{
	if(st==8)
	{
		prn(p,st);
		printf("\n");
		return;
	}
	long i;
	for(i=0;i<vc[p].size();i++)
	{
		if(mat[p][vc[p][i]])
		{
			mat[p][vc[p][i]]=0;
			mat[vc[p][i]][p]=0;
			par[st][vc[p][i]]=p;
			rec(vc[p][i],st+1);
			mat[p][vc[p][i]]=1;
			mat[vc[p][i]][p]=1;
		}
	}
}

int main()
{
	vc[1].push_back(2);
	vc[1].push_back(3);
	vc[1].push_back(5);
	vc[2].push_back(1);
	vc[2].push_back(3);
	vc[2].push_back(5);
	vc[3].push_back(1);
	vc[3].push_back(2);
	vc[3].push_back(4);
	vc[3].push_back(5);
	vc[4].push_back(3);
	vc[4].push_back(5);
	vc[5].push_back(1);
	vc[5].push_back(2);
	vc[5].push_back(3);
	vc[5].push_back(4);

	for(i=1;i<=5;i++)
		for(j=1;j<=5;j++)
			mat[i][j]=1;
	rec(1,0);

	return 0;
}
