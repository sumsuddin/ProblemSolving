#include<stdio.h>
//long i,j,pt,t,bc,tru,a[200];
long st[155],n;
int main()
{
/*	for(i=3;i<151;i++)
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
				if(pt!=2)
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
						pt=2;

					t-=a[pt];
				}
			}
		}
	}
	*/
st[3]= 2;
st[4]= 5;
st[5]= 2;
st[6]= 4;
st[7]= 3;
st[8]= 11;
st[9]= 2;
st[10]= 3;
st[11]= 8;
st[12]= 16;
st[13]= 4;
st[14]= 21;
st[15]= 6;
st[16]= 5;
st[17]= 2;
st[18]= 11;
st[19]= 20;
st[20]= 34;
st[21]= 8;
st[22]= 15;
st[23]= 10;
st[24]= 7;
st[25]= 13;
st[26]= 11;
st[27]= 13;
st[28]= 45;
st[29]= 18;
st[30]= 23;
st[31]= 8;
st[32]= 3;
st[33]= 2;
st[34]= 25;
st[35]= 75;
st[36]= 42;
st[37]= 13;
st[38]= 5;
st[39]= 23;
st[40]= 13;
st[41]= 50;
st[42]= 16;
st[43]= 18;
st[44]= 89;
st[45]= 38;
st[46]= 8;
st[47]= 39;
st[48]= 30;
st[49]= 29;
st[50]= 38;
st[51]= 7;
st[52]= 45;
st[53]= 23;
st[54]= 137;
st[55]= 46;
st[56]= 63;
st[57]= 17;
st[58]= 48;
st[59]= 5;
st[60]= 46;
st[61]= 34;
st[62]= 140;
st[63]= 33;
st[64]= 39;
st[65]= 2;
st[66]= 28;
st[67]= 29;
st[68]= 79;
st[69]= 33;
st[70]= 48;
st[71]= 3;
st[72]= 10;
st[73]= 46;
st[74]= 120;
st[75]= 6;
st[76]= 37;
st[77]= 17;
st[78]= 8;
st[79]= 44;
st[80]= 15;
st[81]= 160;
st[82]= 20;
st[83]= 35;
st[84]= 144;
st[85]= 104;
st[86]= 179;
st[87]= 153;
st[88]= 24;
st[89]= 8;
st[90]= 265;
st[91]= 19;
st[92]= 9;
st[93]= 62;
st[94]= 7;
st[95]= 139;
st[96]= 19;
st[97]= 44;
st[98]= 93;
st[99]= 182;
st[100]= 27;
st[101]= 158;
st[102]= 185;
st[103]= 193;
st[104]= 17;
st[105]= 82;
st[106]= 3;
st[107]= 11;
st[108]= 43;
st[109]= 55;
st[110]= 21;
st[111]= 41;
st[112]= 146;
st[113]= 29;
st[114]= 80;
st[115]= 59;
st[116]= 8;
st[117]= 29;
st[118]= 66;
st[119]= 19;
st[120]= 160;
st[121]= 59;
st[122]= 28;
st[123]= 129;
st[124]= 127;
st[125]= 120;
st[126]= 72;
st[127]= 45;
st[128]= 157;
st[129]= 2;
st[130]= 63;
st[131]= 127;
st[132]= 81;
st[133]= 318;
st[134]= 513;
st[135]= 98;
st[136]= 28;
st[137]= 32;
st[138]= 231;
st[139]= 236;
st[140]= 411;
st[141]= 26;
st[142]= 45;
st[143]= 5;
st[144]= 303;
st[145]= 228;
st[146]= 66;
st[147]= 9;
st[148]= 205;
st[149]= 65;
st[150]= 39;

	while(scanf("%ld",&n),n)
	{
		printf("%ld\n",st[n]);
	}

	return 0;
}