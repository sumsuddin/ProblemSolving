#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

long i,j,m1[150],m2[150],q;
char st[1010],sy[1010],s1[1010],c;


int main()
{
	while(~scanf("%s%s",st,sy))
	{
		for(i='a';i<='z';i++)
			m1[i]=m2[i]=0;

		for(i=0;st[i];i++)
			m1[st[i]]++;

		for(i=0;sy[i];i++)
			m2[sy[i]]++;

		for(i='a';i<='z';i++)
			if(m1[i]>m2[i])
				m1[i]=m2[i];
			else
				m2[i]=m1[i];
		
		q=0;
		for(i=0;st[i];i++)
		{
			c=st[i];

			while(m1[c]--)
				s1[q++]=c;
			m1[c]=0;
		}
		s1[q]=0;
		sort(s1,s1+strlen(s1));
		printf("%s\n",s1);
	}
	return 0;
}
