#include<stdio.h>
#include<string.h>
long i,j,k,p,la,fi,fj,sum,ret,e,max,num[25],cs=1;
bool flag;
char key[25],keyword[25][25],excuse[25][100],st[25];
long amount(char a[])
{
	ret=0;
	la=strlen(a);
	for(fi=0;fi<=la;fi++)
	{
		if(a[fi]>90 && a[fi]<123)
			key[p++]=a[fi]-32;
		else
			if(a[fi]>64 && a[fi]<91)
				key[p++]=a[fi];
			else
			{
				key[p]=0;
				p=0;
				flag=0;
				for(fj=0;fj<k;fj++)
				{
					if(!strcmp(keyword[fj],key))
					{
						flag=1;
						break;
					}
				}
				if(flag)
					ret++;
			}
	}
	return ret;
}

int main()
{
	while(gets(st))
	{
		sscanf(st,"%ld%ld",&k,&e);
		for(i=0;i<k;i++)
		{
			gets(keyword[i]);
			for(max=0;keyword[i][max];max++)
				if(keyword[i][max]>90)
					keyword[i][max]-=32;
		}
		max=0;
		for(i=0;i<e;i++)
		{
			gets(excuse[i]);
			num[i]=amount(excuse[i]);
			if(num[i]>max)
				max=num[i];
		}
		printf("Excuse Set #%ld\n",cs++);
		for(i=0;i<e;i++)
		{	
			if(num[i]==max)
				printf("%s\n",excuse[i]);
		}
		printf("\n");
	}
	return 0;
}