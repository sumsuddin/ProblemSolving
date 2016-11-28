#include<stdio.h>
#include<malloc.h>
bool flag;
long a;

struct node
{
	long data;
	struct node *lf,*ri;
}*p,*q,*r;
void right();

void postorder(node *q)
{
	if(q->lf!=NULL)
		postorder(q->lf);
	if(q->ri!=NULL)
		postorder(q->ri);
	printf("%ld\n",q->data);
}

void left()
{
	flag=1;
			while(q->data>a)
			{
				if(q->lf!=NULL)
					q=q->lf;
				else
				{
					r=(struct node*)malloc(sizeof(struct node));
					r->data=a;
					r->lf=NULL;
					r->ri=NULL;
					q->lf=r;
					flag=0;
					break;
				}
			}
	if(flag)
		right();
}

void right()
{
	flag=1;
			while(q->data<a)
			{
				if(q->ri!=NULL)
					q=q->ri;
				else
				{
					r=(struct node*)malloc(sizeof(struct node));
					r->data=a;
					r->lf=NULL;
					r->ri=NULL;
					q->ri=r;
					flag=0;
					break;
				}
			}
	if(flag)
		left();
}


int main()
{
	while(~scanf("%ld",&a))
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=a;
		p->lf=NULL;
		p->ri=NULL;

		while(~scanf("%ld",&a))
		{
			q=p;
			left();
		}
		postorder(p);
	}
	return 0;
}