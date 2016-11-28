#include<stdio.h>
long d,m,y,n,mst[50],p=1,i;
char s[100];
int main()
{
	mst[1]=31;mst[3]=31;mst[4]=30;mst[5]=31;mst[6]=30;mst[7]=31;mst[8]=31;mst[9]=30;mst[10]=31;mst[11]=30;mst[12]=31;
	gets(s);
	sscanf(s,"%ld",&n);
	while(n--)
	{
		gets(s);
		m=(s[0]-48)*10+(s[1]-48);
		d=(s[2]-48)*10+(s[3]-48);
		y=(s[4]-48)*1000+(s[5]-48)*100+(s[6]-48)*10+(s[7]-48);
		if((y%4==0 && y%100!=0) || y%400==0)
			mst[2]=29;
		else
			mst[2]=28;

		for(i=1;i<281;i++)
		{
			d++;
			if(d>mst[m])
			{
				m++;
				d=1;
				if(m>12)
				{
					m=1;
					y++;
					if((y%4==0 && y%100!=0) || y%400==0)
						mst[2]=29;
					else
						mst[2]=28;
				}
			}
		}

		printf("%ld %02ld/%02ld/%ld ",p++,m,d,y);

		if((m==1 && d>20) || (m==2 && d<20))
			printf("aquarius\n");
		else
			if((m==2 && d>19) || (m==3 && d<21))
				printf("pisces\n");
			else
				if((m==3 && d>20) || (m==4 && d<21))
					printf("aries\n");
				else
					if((m==4 && d>20) || (m==5 && d<22))
						printf("taurus\n");
					else
						if((m==5 && d>21) || (m==6 && d<22))
							printf("gemini\n");
						else
							if((m==6 && d>21) || (m==7 && d<23))
								printf("cancer\n");
							else
								if((m==7 && d>22) || (m==8 && d<22))
									printf("leo\n");					
								else
									if((m==8 && d>21) || (m==9 && d<24))
										printf("virgo\n");
									else
										if((m==9 && d>23) || (m==10 && d<24))
											printf("libra\n");
										else
											if((m==10 && d>23) || (m==11 && d<23))
												printf("scorpio\n");
											else
												if((m==11 && d>22) || (m==12 && d<23))
													printf("sagittarius\n");
												else
													if((m==12 && d>22) || (m==1 && d<21))
														printf("capricorn\n");
	}
	return 0;
}