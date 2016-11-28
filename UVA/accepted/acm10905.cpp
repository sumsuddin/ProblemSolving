#include<stdio.h>
#include<string.h>
long i,j,n,k,l;
char st[100][100],x[100],y[100];
int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%s",st[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				for(k=0;st[i][k];k++)
					x[k]=st[i][k];
				for(l=0;st[j][l];l++)
					x[k++]=st[j][l];
				x[k]=0;


				for(k=0;st[j][k];k++)
					y[k]=st[j][k];
				for(l=0;st[i][l];l++)
					y[k++]=st[i][l];
				y[k]=0;

				if(strcmp(x,y)<0)
				{
					strcpy(x,st[i]);
					strcpy(st[i],st[j]);
					strcpy(st[j],x);
				}
			}
		for(i=0;i<n;i++)
			printf("%s",st[i]);
		printf("\n");
	}
	return 0;
}

/*#include<stdio.h>
#include <iostream>
#include<math.h>
using namespace std;

long double st[100],temp,sy[100],q;
long i,j,n;

void swap()
{
	temp=st[i];
	st[i]=st[j];
	st[j]=temp;

	temp=sy[i];
	sy[i]=sy[j];
	sy[j]=temp;
}
int main()
{
	while(cin>>n && n)
	{
		for(i=0;i<n;i++)
		{
			cin>>st[i];
			sy[i]=st[i];
			if(sy[i]!=0)
				q=(floor)(log(sy[i])/log(10.0));
			sy[i]*=pow(10,(10-q));
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(sy[i]<sy[j])
					swap();
				else
					if(sy[i]==sy[j])
						if(st[i]>st[j])
							swap();
			}
		}
		if(st[0]==0)
			printf("0");
		else
			for(i=0;i<n;i++)
				printf("%.0llf",st[i]);
		printf("\n");
	}
	return 0;
}

*/
/*#include<stdio.h>
#include<string.h>
long i,j,p,n;
char st[100][100],sy[100];
bool com(char as[],char bs[])
{
	for(p=0;as[p];p++)
	{
		if(bs[p]==0)
			return 1;
		else
			if(bs[p]>as[p])
				return 0;
			else
				if(as[p]>bs[p])
					return 1;
	}
	return 0;
}

int main()
{
	while(scanf("%ld",&n),n)
	{
		getchar();
		for(i=0;i<n;i++)
			scanf("%s",&st[i]);
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				if(com(st[i],st[j]))
				{
					strcpy(sy,st[i]);
					strcpy(st[i],st[j]);
					strcpy(st[j],sy);
				}
		}
		while(n--)
			printf("%s",st[n]);
		printf("\n");
	}
	return 0;
}
*/
/*#include<stdio.h>
#include<string.h>
long i,j,n;
double sum[100];
char st[100][100],sr[100];
int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",st[i]);
			sum[i]=0;
			for(j=0;st[i][j];j++)
				sum[i]+=((double)(st[i][j]-48)*(double)((10-j)/10));
			sum[i]+=(10-j)*10;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(sum[i]<sum[j])
				{
					s=sum[i];
					sum[i]=sum[j];
					sum[j]=s;

					strcpy(sr,st[i]);
					strcpy(st[i],st[j]);
					strcpy(st[j],sr);

				}
			}
		}
		for(i=0;i<n;i++)
			puts(st[i]);
	}
	return 0;
}*/
/*#include<stdio.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n
double dou,dot,sy[100];
long i,j,n,st[100],lon;
int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);

		for(i=0;i<n;i++)
		{
			dou=log(st[i])/log(10);
			lon=(long)dou;
			dot=(double)lon;

			dou-=dot;
			if(dou>=1)
				dou-=1;
			sy[i]=dou;
		}

		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(sy[i]<sy[j])
				{
					dou=sy[i];
					sy[i]=sy[j];
					sy[j]=dou;

					swap(st[i],st[j]);
				}
			}
		}
		for(i=n-1;sy[i]==0 && i>=0;i--);
		
		for(;i<n;i++)
		{
            for(j=i+1;j<n;j++)
            {
                if(st[i]>st[j])
                   swap(st[i],st[j]);
            }
        }   


		for(i=0;i<n;i++)
			printf("%ld",st[i]);
		printf("\n");
	}
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
int comp(char *a,char *b)
{
	int j=strlen(b),i=strlen(a),k;

	if(j<i)
		j=i;
	for(i=1;i<=j;i++)
	{
		if(a[i]==0)
		{
			for(i,k=0;i<=j;i++,k++)
			{
				if(b[i]==a[k])
					continue;
				else
				{	if(a[k]==0)
					{
						k=-1;
						i--;
					}
					else
					{
						if(b[i]>a[k])
							return 0;
						else
							return 1;
						break;
					}
				}
			}
		}
		if(b[i]==0)
		{
			for(i,k=0;i<=j;i++,k++)
			{
				if(a[i]==b[k])
					continue;
				else
				{	if(b[k]==0)
						k=0;
					else
					{
						if(a[i]<b[k])
							return 0;
						else
							return 1;
						break;
					}
				}
			}
			if(a[i]>b[i-1])
				return 1;
			else
				return 0;
			break;
		}
		if(a[i]>b[i])
		{
			return 1;
			break;
		}
		else if(a[i]<b[i])
		{
			return 0;
			break;
		}
	}
}

void stswap(char *a,char *b)
{
	char c[1000];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
}


int main()
{
	int n,i,j,d;
	char st[1000][1000];

	while(gets(st[0]))
	{
		if(st[0][0]==0)
			continue;

		if(st[0][0]=='0' && st[0][1]==0)
			break;

		sscanf(st[0],"%d",&n);


		for(i=0;i<n;i++)
			scanf("%s",st[i]);


		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(st[i][0]>=st[j][0])
				{
					d=1;

					if(st[i][0]==st[j][0])						
						d=comp(st[i],st[j]);

					if(d)
						stswap(st[i],st[j]);
				}
			}
		}

		while(n--)
			printf("%s",st[n]);
		printf("\n");
	}
	return 0;
}*/
