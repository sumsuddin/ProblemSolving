#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	char st[100];
	int i,l,j,sy[100],sum;
	sy['I']=1;
	sy['V']=5;
	sy['X']=10;
	sy['L']=50;
	sy['C']=100;
	sy['D']=500;
	sy['M']=1000;


	while(gets(st))
	{
		l=strlen(st);
		for(i=0,j=l-1;i<l/2;i++,j--)
			swap(st[i],st[j]);
		if(st[0]>47 && st[0]<58)
		{
			for(l=l-1;l>=0;l--)
			{
				st[l]-=48;
				if(l==3)
					for(i=0;i<st[l];i++)
						printf("M");
				else
				{
					if(l==2)
					{
						switch (st[l])
						{

						case 0:
							continue;
						case 1:
							case 2:
								case 3:
							for(i=0;i<st[l];i++)
								printf("C");
							break;

								case 4:
									printf("CD");
									break;

								case 5:
									printf("D");
									break;

								case 9:
										printf("CM");
										break;

								default :
										st[l]-=5;
										printf("D");
										for(i=0;i<st[l];i++)
											printf("C");

						}
					}
					else
					{
						if(l==1)
						{
							switch (st[l])
							{
							case 0:
								continue;
							case 1:
								case 2:
									case 3:
								for(i=0;i<st[l];i++)
									printf("X");
								break;

									case 4:
										printf("XL");
										break;

									case 5:
										printf("L");
										break;

									case 9:
											printf("XC");
											break;

									default :
											st[l]-=5;
											printf("L");
											for(i=0;i<st[l];i++)
												printf("X");
							}
						}
						else
						{
							switch (st[l])
							{
							case 0:
								continue;
							case 1:
								case 2:
									case 3:
								for(i=0;i<st[l];i++)
									printf("I");
								break;

									case 4:
										printf("IV");
										break;

									case 5:
										printf("V");
										break;

									case 9:
											printf("IX");
											break;

									default :
											st[l]-=5;
											printf("V");
											for(i=0;i<st[l];i++)
												printf("I");
							}
						}
					}

				}
			}
		}
		else
		{
			sum=0;
			for(i=0;st[i];i++)
			{
				sum+=sy[st[i]];
				if((st[i]=='V' || st[i]=='X') && st[i+1]=='I')
					sum-=2;
				else
				{
					if((st[i]=='L' || st[i]=='C') && st[i+1]=='X')
						sum-=20;
					else
					{
						if((st[i]=='D' || st[i]=='M') && st[i+1]=='C')
							sum-=200;
					}
				}
			}

			printf("%ld",sum);
		}
		printf("\n");
	}
	return 0;
}