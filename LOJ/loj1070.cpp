#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
unsigned long long M[5][5],F[5][5],d[5][5],pp,i,j;
long long n,t,p,q,cs=1;
void rec(long long n)
{
	if(n<2)
		return;

	if(n%2)
		rec(n-1);
	else
		rec(n/2);

	if(n%2)
	{
		d[0][0]=(M[0][0]*F[0][0]) +(M[0][1]*F[1][0]) ;
		d[0][1]=(M[0][0]*F[0][1]) +(M[0][1]*F[1][1]) ;
		d[1][0]=(M[1][0]*F[0][0]) +(M[1][1]*F[1][0]) ;
		d[1][1]=(M[1][0]*F[0][1]) +(M[1][1]*F[1][1]) ;

		M[0][0]=d[0][0] ;M[0][1]=d[0][1] ;M[1][0]=d[1][0] ;M[1][1]=d[1][1] ;
	}
	else
	{
		d[0][0]=(M[0][0]*M[0][0]) +(M[0][1]*M[1][0]) ;
		d[0][1]=(M[0][0]*M[0][1]) +(M[0][1]*M[1][1]) ;
		d[1][0]=(M[1][0]*M[0][0]) +(M[1][1]*M[1][0]) ;
		d[1][1]=(M[1][0]*M[0][1]) +(M[1][1]*M[1][1]) ;

		M[0][0]=d[0][0] ;M[0][1]=d[0][1] ;M[1][0]=d[1][0] ;M[1][1]=d[1][1] ;
	}
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld",&p,&q,&n);

		pp=p*p-2*q;

		M[0][0]=F[0][0]=p;
		M[0][1]=F[0][1]=-q;
		M[1][0]=F[1][0]=1;
		M[1][1]=F[1][1]=0;

		if(n==0)
			printf("Case %lld: %llu\n",cs++,p=2);
		else if(n==1)
			printf("Case %lld: %llu\n",cs++,p);
		else if(n==2)
			printf("Case %lld: %llu\n",cs++,pp);
		else
		{
			rec(n-2);
			printf("Case %lld: %llu\n",cs++,M[0][0]*pp+p*M[0][1]);
		}
	}
	return 0;
}
