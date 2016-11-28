#include<stdio.h>
long st[20][50],mst[20],i,j,d,m;
int main()
{
	mst[1]=31;mst[2]=28;mst[3]=31;mst[4]=30;mst[5]=31;mst[6]=30;mst[7]=31;mst[8]=31;mst[9]=30;mst[10]=31;mst[11]=30;mst[12]=31;
	d=2;
	for(i=1;i<13;i++)
	{
		for(j=1;j<=mst[i];j++)
		{

			st[i][j]=d++;
			if(d==8)
				d=1;
		}
	}
	scanf("%ld",&d);
	while(d--)
	{
		scanf("%ld%ld",&i,&j);
		if(st[i][j]==1)
			printf("Friday\n");
		else
			if(st[i][j]==2)
				printf("Saturday\n");
			else
				if(st[i][j]==3)
					printf("Sunday\n");
				else
					if(st[i][j]==4)
						printf("Monday\n");
					else
						if(st[i][j]==5)
							printf("Tuesday\n");
						else
							if(st[i][j]==6)
								printf("Wednesday\n");
							else
								printf("Thursday\n");
	}
	return 0;
}