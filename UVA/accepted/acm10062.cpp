#include<stdio.h>
#include<string.h>
int main()
{
	char st[1050],sy[1005],c,k=0;
	int a,i,j,test[140];



	while(gets(st))
	{

		if(k)
			printf("\n");
		k=1;

		memset(test,0,sizeof(test));

		for(i=0;st[i] && st[i]!=13;i++)
		{
			test[st[i]]++;
			sy[st[i]]=st[i];				
		}

		for(i=128;i>31;i--)
		{
			for(j=i-1;j>31;j--)
				if(test[i]>=test[j])
				{

					if(test[i]==test[j])
					{
						if(sy[i]>=sy[j])
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

			for(i=128;i>31;i--)
			{
				if(test[i]==0)
					continue;

				printf("%d %d\n",sy[i],test[i]);
			}

	}
			return 0;

}





				///////

/*#include<stdio.h>

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

}*/
