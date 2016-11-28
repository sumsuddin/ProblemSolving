/*#include<stdio.h>
#include<math.h>
long n,i,j,sum,b,c,d;
bool bu[10000050];
bool chk(long a)
{
	b=a;
	while(1)
	{
		c=a%10;
		if(c==0)
			return 0;
		a/=10;

		d=1;
		while(d<=a)
			d*=10;
		a+=(c*d);
		if(a>10000000 || bu[a])
			return 0;
		if(b==a)
			break;
	}
	return 1;
}

int main()
{
	freopen("d://acm//out//494.out", "w", stdout);
	bu[0]=1;
	bu[1]=1;


	for(i=4;i<10000000;i+=2)
		bu[i]=1;

	for(i=3;i<10000000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<10000000;j+=i)
				bu[j]=1;
		}
	}
	sum=0;
	for(i=2;i<10000000;i++)
		if(bu[i]==0)
		{
			if(chk(i))
				printf("st[%ld]= %ld;\n",sum++,i);
		}
	return 0;
}

*/

#include<stdio.h>
long sum,i,d,n,st[100];

int main()
{
st[0]= 2;
st[1]= 3;
st[2]= 5;
st[3]= 7;
st[4]= 11;
st[5]= 13;
st[6]= 17;
st[7]= 31;
st[8]= 37;
st[9]= 71;
st[10]= 73;
st[11]= 79;
st[12]= 97;
st[13]= 113;
st[14]= 131;
st[15]= 197;
st[16]= 199;
st[17]= 311;
st[18]= 337;
st[19]= 373;
st[20]= 719;
st[21]= 733;
st[22]= 919;
st[23]= 971;
st[24]= 991;
st[25]= 1193;
st[26]= 1931;
st[27]= 3119;
st[28]= 3779;
st[29]= 7793;
st[30]= 7937;
st[31]= 9311;
st[32]= 9377;
st[33]= 11939;
st[34]= 19391;
st[35]= 19937;
st[36]= 37199;
st[37]= 39119;
st[38]= 71993;
st[39]= 91193;
st[40]= 93719;
st[41]= 93911;
st[42]= 99371;
st[43]= 193939;
st[44]= 199933;
st[45]= 319993;
st[46]= 331999;
st[47]= 391939;
st[48]= 393919;
st[49]= 919393;
st[50]= 933199;
st[51]= 939193;
st[52]= 939391;
st[53]= 993319;
st[54]= 999331;

	while(scanf("%ld",&n),n)
	{
		d=1;sum=1;
		while(d<=n)
			d*=10;
		for(i=0;i<55;i++)
		{
			if(st[i]<d && st[i]>n)
			{
				printf("%ld\n",st[i]);
				sum=0;
				break;
			}
		}
		if(sum)
		printf("0\n");
	}
	return 0;
}