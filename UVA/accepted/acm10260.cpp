#include<stdio.h>

int main()
{
	char st[25],i,c;

	while(gets(st))
	{
		c=0;
		for(i=0;st[i];i++)
		{
			if(st[i]=='B' || st[i]=='F' || st[i]=='P' || st[i]=='V')
			{
				if(c==1)
					continue;
				printf("1");
				c=1;
			}

			else
			{
				if(st[i]=='C' || st[i]=='G' || st[i]=='J' || st[i]=='K' || st[i]=='Q' || st[i]=='S' || st[i]=='X' || st[i]=='Z')
				{
					if(c==2)
						continue;
					printf("2");
					c=2;
				}

				else
				{
					if(st[i]=='D' || st[i]=='T' )
					{
						if(c==3)
							continue;
						printf("3");
						c=3;
					}

					else
					{
						if(st[i]=='L' )
						{
							if(c==4)
								continue;
							printf("4");
							c=4;
						}

						else
						{
							if(st[i]=='M' || st[i]=='N' )
							{
								if(c==5)
									continue;
								printf("5");
								c=5;
							}

							else
								if(st[i]=='R')
								{
									if(c==6)
										continue;
									printf("6");
									c=6;
								}
								else
									c=0;
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}