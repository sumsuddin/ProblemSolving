#include<stdio.h>
//long i,j,l,pt,t,bc,tru,a[200];
long st[105],n;
int main()
{
/*	for(i=13;i<101;i++)
	{
		for(j=1;j<=i;j++)
			a[j]=1;

		tru=1;

		for(j=1;tru;j++)
		{
			bc=j;
			pt=1;

			while(1)
			{
				if(pt!=13)
					a[pt]=0;
				else
				{
					bc=0;
					for(pt=1;pt<=i;pt++)
						bc+=a[pt];

					if(bc==1)
					{
						tru=0;
						printf("st[%ld]= %ld;\n",i,j);
					}
					else
					{
						for(pt=1;pt<=i;pt++)
							a[pt]=1;
					}
					break;
				}
				t=bc;
				while(t)
				{
					pt++;
					if(pt>i)
					{
						for(l=1;l<14;l++)
							if(a[l])
							{
								pt=l;
								break;
							}
					}

					t-=a[pt];
				}
			}
		}
	}*/
st[13]= 1;
st[14]= 18;
st[15]= 10;
st[16]= 11;
st[17]= 7;
st[18]= 17;
st[19]= 11;
st[20]= 15;
st[21]= 29;
st[22]= 5;
st[23]= 21;
st[24]= 13;
st[25]= 26;
st[26]= 14;
st[27]= 11;
st[28]= 23;
st[29]= 22;
st[30]= 9;
st[31]= 73;
st[32]= 17;
st[33]= 42;
st[34]= 7;
st[35]= 98;
st[36]= 15;
st[37]= 61;
st[38]= 22;
st[39]= 84;
st[40]= 24;
st[41]= 30;
st[42]= 9;
st[43]= 38;
st[44]= 15;
st[45]= 54;
st[46]= 27;
st[47]= 9;
st[48]= 61;
st[49]= 38;
st[50]= 22;
st[51]= 19;
st[52]= 178;
st[53]= 38;
st[54]= 53;
st[55]= 79;
st[56]= 68;
st[57]= 166;
st[58]= 20;
st[59]= 9;
st[60]= 22;
st[61]= 7;
st[62]= 21;
st[63]= 72;
st[64]= 133;
st[65]= 41;
st[66]= 10;
st[67]= 82;
st[68]= 92;
st[69]= 64;
st[70]= 129;
st[71]= 86;
st[72]= 73;
st[73]= 67;
st[74]= 19;
st[75]= 66;
st[76]= 115;
st[77]= 52;
st[78]= 24;
st[79]= 22;
st[80]= 176;
st[81]= 10;
st[82]= 57;
st[83]= 137;
st[84]= 239;
st[85]= 41;
st[86]= 70;
st[87]= 60;
st[88]= 116;
st[89]= 81;
st[90]= 79;
st[91]= 55;
st[92]= 102;
st[93]= 49;
st[94]= 5;
st[95]= 22;
st[96]= 54;
st[97]= 52;
st[98]= 113;
st[99]= 15;
st[100]= 66;
while(scanf("%ld",&n),n)
{
	printf("%ld\n",st[n]);
}
	return 0;
}