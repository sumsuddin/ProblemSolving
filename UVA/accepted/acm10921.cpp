#include<stdio.h>

int main()
{
	char st[32],i,j;
	while(gets(st))
	{
		j=0;
		for(i=0;st[i];i++)
		{
			if(st[i]=='-')
				printf("-");
			else
			{
				if(st[i]>64 &&st[i]<68)
					printf("2");
				else
				{
					if(st[i]>67 &&st[i]<71)
						printf("3");
					else
					{
						if(st[i]>70 &&st[i]<74)
							printf("4");
						else
						{
							if(st[i]>73 && st[i]<77)
								printf("5");
							else
							{
								if(st[i]>76 && st[i]<80)
									printf("6");

								else
								{
									if(st[i]>79 && st[i]<84)
										printf("7");
									else
									{
										if(st[i]>83 && st[i]<87)
											printf("8");
										else
										{
											if(st[i]>86 && st[i]<91)
												printf("9");
											else
											{
												if(st[i]=='1')
													printf("1");
												else
												{
													if(st[i]=='0')
														printf("0");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
