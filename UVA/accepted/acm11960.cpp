#include<stdio.h>
#include<math.h>
long i,n,sq,st[500];
int main()
{
st[0]=2;
st[1]=3;
st[2]=4;
st[3]=6;
st[4]=8;
st[5]=10;
st[6]=12;
st[7]=18;
st[8]=20;
st[9]=24;
st[10]=30;
st[11]=36;
st[12]=48;
st[13]=60;
st[14]=72;
st[15]=84;
st[16]=90;
st[17]=96;
st[18]=108;
st[19]=120;
st[20]=168;
st[21]=180;
st[22]=240;
st[23]=336;
st[24]=360;
st[25]=420;
st[26]=480;
st[27]=504;
st[28]=540;
st[29]=600;
st[30]=630;
st[31]=660;
st[32]=672;
st[33]=720;
st[34]=840;
st[35]=1080;
st[36]=1260;
st[37]=1440;
st[38]=1680;
st[39]=2160;
st[40]=2520;
st[41]=3360;
st[42]=3780;
st[43]=3960;
st[44]=4200;
st[45]=4320;
st[46]=4620;
st[47]=4680;
st[48]=5040;
st[49]=7560;
st[50]=9240;
st[51]=10080;
st[52]=12600;
st[53]=13860;
st[54]=15120;
st[55]=18480;
st[56]=20160;
st[57]=25200;
st[58]=27720;
st[59]=30240;
st[60]=32760;
st[61]=36960;
st[62]=37800;
st[63]=40320;
st[64]=41580;
st[65]=42840;
st[66]=43680;
st[67]=45360;
st[68]=50400;
st[69]=55440;
st[70]=65520;
st[71]=75600;
st[72]=83160;
st[73]=98280;
st[74]=110880;
st[75]=131040;
st[76]=138600;
st[77]=151200;
st[78]=163800;
st[79]=166320;
st[80]=196560;
st[81]=221760;
st[82]=262080;
st[83]=277200;
st[84]=327600;
st[85]=332640;
st[86]=360360;
st[87]=393120;
st[88]=415800;
st[89]=443520;
st[90]=471240;
st[91]=480480;
st[92]=491400;
st[93]=498960;
st[94]=554400;
st[95]=655200;
st[96]=665280;
st[97]=720720;
st[98]=831600;
st[99]=942480;
st[100]=982800;
st[101]=997920;


	scanf("%ld",&sq);
	while(sq--)
	{
		scanf("%ld",&n);
		if(n<=9240)
		{
                   if(n==1)
                   printf("1\n");
                   else
                   {
                       for(i=50;i>=0;i--)
                       {
                  			if(st[i]<=n)
                			{
                				printf("%ld\n",st[i]);
                				break;
                			}
                        }
                   }
        }
        else
        {
    		for(i=101;i>49;i--)
    			if(st[i]<=n)
    			{
    				printf("%ld\n",st[i]);
    				break;
    			}
        }
	}
	return 0;
}
