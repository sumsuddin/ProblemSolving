#include<stdio.h>

int main()
{
	char st[1005],sy[30],c;
	int a ,n,i,j,k,test[30];

	scanf("%d ",&n);

	for(i=0;i<26;i++)
	{
		sy[i]='A'+i;
		test[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		gets(st);
	
		for(j=0;st[j]!=0;j++)
		{
			if(st[j]>96 && st[j]<123)
				st[j]-=32;

			for(k=0;k<26;k++)
				if(st[j]==sy[k])
					test[k]++;
		}
	}

	for(i=25;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
			if(test[i]>=test[j])
			{

				if(test[i]==test[j])
				{
					if(sy[i]>sy[j])
						continue;
				}

				a=test[i];
				test[i]=test[j];
				test[j]=a;

				c=sy[i];
				sy[i]=sy[j];
				sy[j]=c;

				if(test[i]==0)
					break;
			}
	}


			for(i=0;i<26;i++)
			{
				if(test[i]==0)
					break;

				printf("%c %d\n",sy[i],test[i]);
			}
			return 0;

}
