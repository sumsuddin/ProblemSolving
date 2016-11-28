#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	char st[100],str[100];
	int i,l,j,sy[100],sum,pr;
	sy['I']=1;
	sy['V']=5;
	sy['X']=10;
	sy['L']=50;
	sy['C']=100;
	sy['D']=500;
	sy['M']=1000;


	while(gets(st))
	{
		j=pr=0;
		for(i=0;st[i];i++)
			if(st[i]!=' ')
				st[j++]=st[i];
		st[j]=0;
		l=strlen(st);
		for(i=0,j=l-1;i<l/2;i++,j--)
			swap(st[i],st[j]);

			for(l=l-1;l>=0;l--)
			{
				st[l]-=48;
				if(l==3)
					for(i=0;i<st[l];i++)
						str[pr++]='M';
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
								str[pr++]='C';
							break;

								case 4:
									str[pr++]='C',str[pr++]='D';
									break;

								case 5:
									str[pr++]='D';
									break;

								case 9:
										str[pr++]='C',str[pr++]='M';
										break;

								default :
										st[l]-=5;
										str[pr++]='D';
										for(i=0;i<st[l];i++)
											str[pr++]='C';

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
									str[pr++]='X';
								break;

									case 4:
										str[pr++]='X',str[pr++]='L';
										break;

									case 5:
										str[pr++]='L';
										break;

									case 9:
											str[pr++]='X',str[pr++]='C';
											break;

									default :
											st[l]-=5;
											str[pr++]='L';
											for(i=0;i<st[l];i++)
												str[pr++]='X';
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
									str[pr++]='I';
								break;

									case 4:
										str[pr++]='I',str[pr++]='V';
										break;

									case 5:
										str[pr++]='V';
										break;

									case 9:
											str[pr++]='I',str[pr++]='X';
											break;

									default :
											st[l]-=5;
											str[pr++]='V';
											for(i=0;i<st[l];i++)
												str[pr++]='I';
							}
						}
					}

				}
			}
		str[pr]=sum=0;
		for(i=0;str[i];i++)
			if(str[i]=='M')
				sum+=4;
			else if(str[i]=='D')
				sum+=3;
			else if(str[i]=='C')
				sum+=2;
			else if(str[i]=='L')
				sum+=2;
			else if(str[i]=='X')
				sum+=2;
			else if(str[i]=='V')
				sum+=2;
			else
				if(str[i]=='I')
					sum++;
		printf("%ld\n",sum);
	}
	return 0;
}