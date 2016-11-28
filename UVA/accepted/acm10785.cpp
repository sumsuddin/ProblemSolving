#include<stdio.h>
#include<algorithm>
using namespace std;
long i,p,q,vl,cn,cs=1,t,d,n,v,vc;
char pt[10],st[30],sr[250],sl[250];
int main()
{
	pt[1]='A';
	pt[2]='U';
	pt[3]='E';
	pt[4]='O';
	pt[5]='I';

	st[1]='J';
	st[2]='S';
	st[3]='B';
	st[4]='K';
	st[5]='T';
	st[6]='C';
	st[7]='L';
	st[8]='D';
	st[9]='M';
	st[10]='V';
	st[11]='N';
	st[12]='W';
	st[13]='F';
	st[14]='X';
	st[15]='G';
	st[16]='P';
	st[17]='Y';
	st[18]='H';
	st[19]='Q';
	st[20]='Z';
	st[21]='R';


	scanf("%ld",&t);
	while(t--)
	{
		cn=vl=v=vc=0;

		d=p=q=1;
		scanf("%ld",&n);
		printf("Case %ld: ",cs++);
		while(n--)
		{
			if(d>0 || q>21)
			{
				sr[v++]=pt[p];
				vl++;
			}
			else
			{
				sl[vc++]=st[q];
				cn++;
			}
			if(cn>=5)
			{
				q++;
				cn=0;
			}
			if(vl>=21)
			{
				p++;
				vl=0;
			}

			d*=-1;
		}
		sr[v]=0;sl[vc]=0;

		sort(sr,sr+v);
		sort(sl,sl+vc);
		p=q=0;
		for(i=0;i<v+vc;i++)
		{
			if((i%2 && p<vc) || q>=v)
				printf("%c",sl[p++]);
			else
				printf("%c",sr[q++]);
		}
		printf("\n");
	}
	return 0;
}