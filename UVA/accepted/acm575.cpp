#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	char i,j,st[50];
	unsigned long int sum;
	int len;

	while(gets(st))
	{
		if(!strcmp(st,"0"))
			break;
		sum=0;
		len=strlen(st);

		for(i=0,j=len-1;i<len;i++,j--)
			sum+=(st[j]-48)*(pow(2,i+1)-1);
		printf("%u\n",sum);
	}
}