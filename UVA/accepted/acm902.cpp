#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long n,i,j,k,sum,ma,ty,l,p,q;
char st[10000000],sy[10000000][20],ans[20];
bool flag;
int srt(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}
void count()
{
	p=0;
	for(i=0;i<l;i++)
	{
		q=0;
		for(j=0;j<n;j++)
			sy[i][q++]=st[i+j];
		sy[i][q]=0;
	}
}

int main()
{
	while(scanf("%ld%s",&n,st)==2)
	{
		l=strlen(st)-n+1;
		count();

		qsort((void *) sy,i,sizeof(sy[0]),srt);

		strcpy(st,sy[0]);

		ma=0;
		for(j=1;j<i;j++)
		{
			sum=1;
			while(strcmp(st,sy[j])==0)
			{
				sum++;
				j++;
			}
			if(sum>ma)
			{
				ma=sum;
				strcpy(ans,st);
			}
			strcpy(st,sy[j]);
		}
		puts(ans);
	}
	return 0;
}