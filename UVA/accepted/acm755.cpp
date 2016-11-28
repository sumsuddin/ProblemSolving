#include<stdio.h>
#include<set>
using namespace std;

long i,t,n,cnv[100],a,ss[10000005],bc;
bool flag;
char st[20];



int main()
{
set<long>mst;
set<long>::iterator it;

cnv['A']=2;
cnv['B']=2;
cnv['C']=2;
cnv['D']=3;
cnv['E']=3;
cnv['F']=3;
cnv['G']=4;
cnv['H']=4;
cnv['I']=4;
cnv['J']=5;
cnv['K']=5;
cnv['L']=5;
cnv['M']=6;
cnv['N']=6;
cnv['O']=6;
cnv['P']=7;
cnv['R']=7;
cnv['S']=7;
cnv['T']=8;
cnv['U']=8;
cnv['V']=8;
cnv['W']=9;
cnv['X']=9;
cnv['Y']=9;

cnv['0']=0;
cnv['1']=1;
cnv['2']=2;
cnv['3']=3;
cnv['4']=4;
cnv['5']=5;
cnv['6']=6;
cnv['7']=7;
cnv['8']=8;
cnv['9']=9;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		bc=0;

		while(n--)
		{
			scanf("%s",st);
			a=0;

			for(i=0;st[i];i++)
			{
				if(st[i]>64 && st[i]<91 || st[i]>47 && st[i]<58) 
					a=a*10+cnv[st[i]];
			}
			mst.insert(a);
			if(bc==mst.size())
				ss[a]++;
			else
			{
				bc++;
				ss[a]=1;
			}
		}
		flag=1;
		for ( it=mst.begin() ; it != mst.end(); it++ )
		{
			if(ss[*it]>1)
			{
				printf("%03ld-%04ld %ld\n",*it/10000,*it%10000,ss[*it]);
				flag=0;
			}
		}
		if(flag)
			printf("No duplicates.\n");
		
		mst.clear();
		if(t)
			printf("\n");
	}
	return 0;
}