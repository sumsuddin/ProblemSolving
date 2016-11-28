#include<stdio.h>
#include<string.h>
#include<math.h>
long value[100],i,j,n,cs=1;
long double sum;
char st[50];

int main()
{
	value['A']=0;
	value['C']=1;
	value['G']=2;
	value['T']=3;

	scanf("%ld",&n);

	while(n--)
	{
		sum=0;
		scanf("%s",st);
		printf("Case %ld: (%ld",cs++,strlen(st));

		for(i=0,j=strlen(st)-1;st[i];i++,j--)
			sum+=(value[st[i]]*pow(4,j));
		printf(":%.0llf)\n",sum);
	}
	return 0;
}