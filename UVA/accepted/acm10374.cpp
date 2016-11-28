#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<string>
using namespace std;
map<string,long>mp;
long i,n,m,t,mm,ll;
char sy[100];
struct ss
{
	long num;
	char st[100],part[100];
}sr[100];
int cmp(const void *a,const void *b)
{
	return (((ss*)a)->num)-(((ss*)b)->num);
}
void elm()
{
	for(mm=0;sy[mm];mm++)
		if(sy[mm]!=' ')
			break;
	ll=0;
	for(mm;sy[mm];mm++)
		sy[ll++]=sy[mm];
	sy[ll]=0;
	for(mm=strlen(sy)-1;mm;mm--)
		if(sy[mm]!=' ')
			break;
	sy[mm+1]=0;
}
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		getchar();

		for(i=1;i<=n;i++)
		{
lli:
			gets(sy);
			elm();
			if(sy[0]==0)
				goto lli;
			strcpy(sr[i].st,sy);

			mp[sr[i].st]=i;
llj:
			gets(sy);
			elm();
			if(sy[0]==0)
				goto llj;

			strcpy(sr[i].part,sy);
			sr[i].num=0;
		}
		scanf("%ld",&m);
		getchar();

		while(m--)
		{
llk:
			gets(sy);
			elm();
			if(sy[0]==0)
				goto llk;
			sr[mp[sy]].num++;
		}
		sr[0].num=0;
		qsort(sr,n+1,sizeof(sr[0]),cmp);
		mp.clear();
		if(sr[n].num==sr[n-1].num)
			printf("tie\n");
		else
			printf("%s\n",sr[n].part);
		if(t)
			printf("\n");
	}
	return 0;
}