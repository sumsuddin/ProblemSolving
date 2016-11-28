#include<stdio.h>
#include<string.h>
long i,j,k,p,n,m;
bool flag,go;
char st[10050][20];
bool com()
{
	go=1;
	for(k=0;st[i][k] && st[j][k];k++)
		if(st[i][k]!=st[j][k])
		{
			go=0;
			break;
		}
	return go;
}

int main()
{
	gets(st[0]);
	sscanf(st[0],"%ld",&n);
	while(n--)
	{
		flag=1;
		gets(st[0]);
		sscanf(st[0],"%ld",&m);
		for(i=0;i<m;i++)
			gets(st[i]);
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if(com())
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
				break;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
