#include<stdio.h>
#include<math.h>
double A,ans;
char st[50];
long i;

int main()
{
	A=(double)((double)10000000/(double)8640000);

	while(gets(st))
	{
		ans=0;
		for(i=0;i<6;i+=2)
			ans=60*ans+((st[i]-48)*10+(st[i+1]-48));

		ans=A*(100*ans+((st[i]-48)*10+(st[i+1]-48)));
		ans=floor(ans);
		printf("%07.0lf\n",ans);
	}
	return 0;
}