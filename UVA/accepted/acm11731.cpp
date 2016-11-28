#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795
long double a,b,c,D,E,F,DE,EF,FD,conD,conE,conF,m,l,k,s,area,A,B,C,de1,de2,ef1,ef2,fd1,fd2,r1,r2,r3;
long cs=1;
int main()
{
	while(scanf("%llf%llf%llf",&a,&b,&c) && (a!=0.0 || b!=0.0 || c!=0.0))
	{
		A=(acos((c*c+b*b-a*a)/(2*c*b))*180)/pi;
		B=(acos((a*a+c*c-b*b)/(2*a*c))*180)/pi;
		C=(acos((a*a+b*b-c*c)/(2*a*b))*180)/pi;

		k=(A+B)/2;
		l=(B+C)/2;
		m=(C+A)/2;

		D=((180-l-k)*pi)/180;
		E=((180-l-m)*pi)/180;
		F=((180-m-k)*pi)/180;

		k=(k*pi)/180;
		l=(l*pi)/180;
		m=(m*pi)/180;

		conD=b/sin(D);
		conE=c/sin(E);
		conF=a/sin(F);

		de1=conD*sin(k);
		de2=conE*sin(m);
		ef1=conE*sin(l);
		ef2=conF*sin(k);
		fd1=conF*sin(m);
		fd2=conD*sin(l);

		DE=de1+de2;
		EF=ef1+ef2;
		FD=fd1+fd2;

		s=(DE+EF+FD)/2;

		area=sqrt(s*(s-DE)*(s-EF)*(s-FD));

		printf("Case %ld: %.2llf ",cs++,area);

		s=(de1+fd2+b)/2;
		r1=(sqrt(s*(s-de1)*(s-fd2)*(s-b))*2)/b;

		s=(ef1+de2+c)/2;
		r2=(sqrt(s*(s-ef1)*(s-de2)*(s-c))*2)/c;

		s=(fd1+ef2+a)/2;
		r3=(sqrt(s*(s-fd1)*(s-ef2)*(s-a))*2)/a;

		area=(((r1*r1)*D)/2)+(((r2*r2)*E)/2)+(((r3*r3)*F)/2);
		printf("%.2llf\n",area);
	}
	return 0;
}