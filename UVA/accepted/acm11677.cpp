#include<stdio.h>

int main()
{
	int h1,h2,m1,m2,m;
	while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2))
	{
		if(h1+m1+h2+m2)
		{
			if(h1==h2)
			{
				if(m1>m2)
				{
					h2+=24;
					m=(h2*60+m2)-(h1*60+m1);
				}

				else
					m=m2-m1;
			}
			else
			{
				if(h1>h2)
				{
					h2+=24;
					m=(h2*60+m2)-(h1*60+m1);
				}
				else
					m=(h2*60+m2)-(h1*60+m1);
			}
			printf("%d\n",m);
		}
		else
			break;
	}
	return 0;
}