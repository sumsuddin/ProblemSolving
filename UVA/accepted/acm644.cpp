#include<stdio.h>
#include<string.h>
long i,j,k,p,n,m,cs=1;
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
	while(gets(st[0]))
	{
		if(st[0][0]=='9')
			continue;
		flag=1;
		m=1;
		while(gets(st[m]))
			if(st[m++][0]=='9')
				break;

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
			printf("Set %ld is immediately decodable\n",cs++);
		else
			printf("Set %ld is not immediately decodable\n",cs++);
	}
	return 0;
}
