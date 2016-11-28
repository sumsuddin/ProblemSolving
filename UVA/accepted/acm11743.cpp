#include<stdio.h>

int main()
{
	long int i,x,y,n;
	char st[25];
	gets(st);

	sscanf(st,"%ld",&n);

	while(n--)
	{
		gets(st);
		x=y=i=0;


		for(i=0;st[i];i++)
		{

			if(i==0 || i==2 || i==5 || i==7 || i==10 || i==12 || i==15 || i==17)
			{
				st[i]=(st[i]-48)*2;
				if(st[i]>9)
					st[i]=(st[i]%10)+1;
				x+=st[i];
			}
			else
				if(st[i]!=32)
					y+=st[i]-48;

		}
		
		x+=y;
		if((x%10)==0)
			printf("Valid\n");
		else
			printf("Invalid\n");
	}
	return 0;
}