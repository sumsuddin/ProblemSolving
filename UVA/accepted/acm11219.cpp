#include<stdio.h>
int main()
{
	long n,d1,d2,m1,m2,y1,y2,p=1;
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld/%ld/%ld",&d1,&m1,&y1);
		scanf("%ld/%ld/%ld",&d2,&m2,&y2);

		if(d1<d2)
			m2++;
		if(m1<m2)
			y2++;
		

		y1-=y2;

		if(y1<0)
			printf("Case #%ld: Invalid birth date\n",p++);
		else
			if(y1>130)
				printf("Case #%ld: Check birth date\n",p++);
			else
				printf("Case #%ld: %ld\n",p++,y1);
	}
	return 0;
}