#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y)  (((x) < (y)) ? -1 : ((x)==(y)) ? 0 : 1 )

typedef struct polyNode{
	float coef;
	int expon;
	struct polyNode *link;
}polyNode;

typedef struct poly{
	polyNode *front;
	polyNode *rear;
}poly;

poly *createPoly();
void newPolyNode(poly *p, float coef,int expon);
poly *add(poly *a, poly *b);
void show(poly *p);
int emptyPoly(poly *p);

int main(void)
{
	poly *a = createPoly();
	poly *b = createPoly();
	poly *c = createPoly();

	/* a(x) = (2*x^1000) + 1 */
	newPolyNode(a, 2.f, 1000);		// (poly*, coef, expon)
	newPolyNode(a, 1.f, 0);

	printf("a(x) = ");
	show(a);
	printf("\n\n");


	/* b(x) = (x^4) + (10*x^3) + (3*x^2) + x */
	newPolyNode(b, 1.f, 4);		// (poly*, coef, expon)
	newPolyNode(b, 10.f, 3);
	newPolyNode(b, 3.f, 2);
	newPolyNode(b, 1.f, 0);

	printf("b(x) = ");
	show(b);
	printf("\n\n");

	c = add(a, b);
	
	printf("c(x) = ");
	show(c);
	printf("\n\n");
	
	
	
	return 0;
}
poly *createPoly()
{
	poly *init=(poly*)malloc(sizeof(poly));
	init->front=NULL;
	init->rear=NULL;
	return init;

}
void newPolyNode(poly *p, float coef,int expon)
{
	polyNode *newnode=(polyNode*)malloc(sizeof(polyNode));
	newnode->coef=coef;
	newnode->expon=expon;
	newnode->link=NULL;
	
	if(emptyPoly(p))
	{
		p->front=newnode;
		p->rear=newnode;
		
	}else
	{
		p->rear->link=newnode;
		p->rear=newnode;
		
	}
}
poly *add(poly *a, poly *b)
{
	poly *temp;
	polyNode *currA,*currB;
	
	int sum=0;
	currA=a->front;
	currB=b->front;
	
	temp=createPoly();
	
	while (currA && currB)
	{

		switch (COMPARE(currA->expon, currB->expon)) 
		{
			case -1 :  //  A < B
				newPolyNode(temp,currB->coef, currB->expon);
				currB = currB->link;
				break;
			case 0 :   //  ==
				sum = currA->coef + currB->coef;
				if (sum) 
					newPolyNode(temp, sum, currA->expon);
				currA = currA->link;
				currB = currB->link;
				break;
			case 1 :   //   A>B
				newPolyNode(temp, currA->coef, currA->expon);
				currA = currA->link;
		}
	}
	if (currA == NULL)
	{		for (; currB; currB = currB->link)
				newPolyNode(temp, currB->coef, currB->expon);
	}else
	{
			for (; currA; currA = currA->link)
				newPolyNode(temp, currA->coef, currA->expon);
	}
	return temp;
}
void show(poly *p)
{
	polyNode *temp = p->front;
	while (temp != NULL)
	{
		printf("%.1fx^%d", temp->coef, temp->expon);		
		if (temp->link != NULL)
			printf(" + ");
		else
			return;

		temp=temp->link;
	}
}
int emptyPoly(poly *p)
{
	if(p->rear==NULL)
	{
		return 1;
	}
	return 0;
}





















