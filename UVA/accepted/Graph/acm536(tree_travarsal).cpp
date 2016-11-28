#include<stdio.h>
#include<string.h>
#include<stack>
#include<malloc.h>
long in,t,pr,nn;
using namespace std;
char st[100],sy[100];
stack<char>stk;
struct node
{
	char vlu;
	node *l,*r;
}*pp,*qq;

void pre(node *p)
{
	if(st[pr]==sy[in])
	{
		p->vlu=st[pr++],in++;

		if((stk.empty() || stk.top()!=sy[in]) && pr<nn)
		{
			pp=(struct node*) malloc(sizeof(node));
			pp->l=NULL;
			pp->r=NULL;
			p->r=pp;
			pre(pp);
		}
		else
		{
			in++;
			if(!stk.empty())
				stk.pop();
		}
	}
	else
	{
		if(pr<nn)
		{
			stk.push(st[pr]);
			p->vlu=st[pr++];

			pp=(struct node*) malloc(sizeof(node));
			pp->l=NULL;
			pp->r=NULL;
			p->l=pp;
			pre(pp);
		}

		if((stk.empty() || stk.top()!=sy[in]) && pr<nn)
		{
			pp=(struct node*) malloc(sizeof(node));
			pp->l=NULL;
			pp->r=NULL;
			p->r=pp;
			pre(pp);
		}
		else
		{
			in++;
			if(!stk.empty())
				stk.pop();
		}
	}
}
void post(node *p)
{
	if(p==NULL)
		return;

	post(p->l);
	post(p->r);
	printf("%c",p->vlu);
}

int main()
{
	while(~scanf("%s%s",st,sy))
	{
		nn=strlen(st);
		node *p,*strt;
		p=(struct node*) malloc(sizeof(node));
		p->l=NULL;
		p->r=NULL;
		strt=p;
		qq=strt;

		in=pr=0;
		pre(strt);
		post(strt);
		printf("\n");
		while(!stk.empty())
			stk.pop();
	}
	return 0;
}