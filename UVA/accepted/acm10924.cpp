#include<stdio.h>
#include<math.h>
int main()
{
	int sum,i,a;
	char st[120],sy[25],p;
st[65]=27;
st[66]=28;
st[67]=29;
st[68]=30;
st[69]=31;
st[70]=32;
st[71]=33;
st[72]=34;
st[73]=35;
st[74]=36;
st[75]=37;
st[76]=38;
st[77]=39;
st[78]=40;
st[79]=41;
st[80]=42;
st[81]=43;
st[82]=44;
st[83]=45;
st[84]=46;
st[85]=47;
st[86]=48;
st[87]=49;
st[88]=50;
st[89]=51;
st[90]=52;

st[97]=1;
st[98]=2;
st[99]=3;
st[100]=4;
st[101]=5;
st[102]=6;
st[103]=7;
st[104]=8;
st[105]=9;
st[106]=10;
st[107]=11;
st[108]=12;
st[109]=13;
st[110]=14;
st[111]=15;
st[112]=16;
st[113]=17;
st[114]=18;
st[115]=19;
st[116]=20;
st[117]=21;
st[118]=22;
st[119]=23;
st[120]=24;
st[121]=25;
st[122]=26;


	while(gets(sy))
	{
		sum=p=0;
		for(i=0;sy[i];i++)
			sum+=st[sy[i]];

			a=sum/2+1;

			for(i=2;i<=a;i++)
			{
				if(sum%i==0)
				{
					p=1;
					break;
				}
			}

			if(p && sum!=2)
				printf("It is not a prime word.\n");

			else
				printf("It is a prime word.\n");

	}
	return 0;
}