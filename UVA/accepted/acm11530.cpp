#include<stdio.h>

int main()
{
	long int n,sum,i,p=1;
	char st[500],sy[500];
st[97]=1;
st[98]=2;
st[99]=3;
st[100]=1;
st[101]=2;
st[102]=3;
st[103]=1;
st[104]=2;
st[105]=3;
st[106]=1;
st[107]=2;
st[108]=3;
st[109]=1;
st[110]=2;
st[111]=3;
st[112]=1;
st[113]=2;
st[114]=3;
st[115]=4;
st[116]=1;
st[117]=2;
st[118]=3;
st[119]=1;
st[120]=2;
st[121]=3;
st[122]=4;
st[32]=1;

	gets(sy);
	sscanf(sy,"%ld",&n);
	while(n--)
	{
		gets(sy);
		sum=0;
		for(i=0;sy[i];i++)
			sum+=st[sy[i]];
		printf("Case #%ld: %ld\n",p++,sum);
	}
	return 0;
}