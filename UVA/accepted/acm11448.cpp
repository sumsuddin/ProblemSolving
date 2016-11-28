#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n
	
char st[10005],sy[10005],sw[10005];
int i,j,la,n;
bool d;

void sub(char a[],char b[])
{

	j=strlen(a);
	la=j/2;

	for(i=0,j=j-1;i<la;i++,j--)
	{
		swap(a[i],a[j]);
	}
	j=strlen(b);
	la=j/2;

	for(i=0,j=j-1;i<la;i++,j--)
	{
		swap(b[i],b[j]);
	}
	for(i=0;b[i];i++)
	{
		if(a[i]<b[i])
		{
			a[i]+=10;
			a[i+1]--;
		}

		a[i]=a[i]-b[i]+48;
	}
	j=strlen(a);
	la=j/2;
	for(i=0,j=j-1;i<la;i++,j--)
	{
		swap(a[i],a[j]);
	}
}
int main()
{

	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		d=0;
		scanf("%s %s",st,sy);
		if(strlen(st)<strlen(sy))
		{
			strcpy(sw,st);
			strcpy(st,sy);
			strcpy(sy,sw);
			d=1;
		}
		else

		if(strlen(st)==strlen(sy))
		{
			for(i=0;st[i]==sy[i] && sy[i];i++);
			if(st[i]<sy[i])
			{
				strcpy(sw,st);
				strcpy(st,sy);
				strcpy(sy,sw);
				d=1;
			}
		}

		sub(st,sy);

		for(i=0;st[i]=='0';i++);
		for(j=0;st[i];i++,j++)
            st[j]=st[i];
		st[j]=0;
		if(st[0]==0)
		{
			st[0]='0';
			st[1]=0;
		}

		if(d)
			printf("-%s\n",st);
		else
			printf("%s\n",st);
	}
	return 0;
}