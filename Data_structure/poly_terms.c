
#include <stdio.h>

#include <stdio.h>

#define COMPARE(X,Y) ((X)<(Y)) ? -1 :(((X)==(Y))?0:1) 
#define MAX_TERMS 100 

typedef struct {
	float coef;//���	
	int expon; //����   
}polynomial; 


polynomial terms[MAX_TERMS]={0};

int startA,finishA,startB,finishB,avail;
int startD,finishD;

void padd(int startA,int finishA,int startB,int finishB,int *startD,int *finishD);
void attach(float coefficient,int exponent);

int main(void)
{
	// A(X)=(2*X^1000 +1)
	// B(X)=(X^4)+(10*X^3)+(3*X^2)+1;
	int i;
	startA=0;
	finishA=1;
	startB=2; 
	finishB=5;  // �ε���
	
	avail=6;
		 
	terms[0].coef=2;//��� 
	terms[0].expon=1000;//���� 
	
	terms[1].coef=1;
	terms[1].expon=0;
	//---------------------A(X)  
	terms[2].coef=1;
	terms[2].expon=4;
	
	terms[3].coef=10;
	terms[3].expon=3;
	
	terms[4].coef=3;
	terms[4].expon=2;
	
	terms[5].coef=1;
	terms[5].expon=0;
	//------------------b(x) 
	//D(X)=A(X)+B(X)
	
	padd(startA,finishA,startB,finishB,&startD,&finishD);
	//PRINT D(X);
	printf("D(X)=");
	
	for(i=startD;i<=finishD;i++,startD++)
	{
		printf("(%.1f * x^%d)",terms[startD].coef,terms[startD].expon);
		
		if(i<finishD)
		{
			printf("+");
	    }
	}
	printf("\n\n");

}

void attach(float coefficient,int exponent)//d������ ���� ��� �߰�  
{
	if(avail>=MAX_TERMS)
	{
		fprintf(stderr,"TOO many terms in polynomials");
		exit(1);
	 } 
	 terms[avail].coef=coefficient;
	 terms[avail++].expon=exponent;
}

void padd(int startA,int finishA,int startB,int finishB,int *startD,int *finishD)
{
	float coefficient;
	*startD=avail;
	
	while(startA<=finishA && startB<=finishB)
	{
		switch(COMPARE(terms[startA].expon,terms[startB].expon))
		{
			case -1://A�� ������ ������ ?   
				attach(terms[startB].coef,terms[startB].expon);
				startB++;
				break;
			case 0: //������ ������
			    coefficient=terms[startA].coef+terms[startB].coef;
				if(coefficient)
					attach(coefficient,terms[startA].expon);
				startA++;
				startB++;
				break;
			case 1://A�� ������ ū�� ? 
			    attach(terms[startA].coef,terms[startA].expon);
				startA++;
		}
	}
	for(;startA<=finishA;startA++)
	   	attach(terms[startA].coef,terms[startA].expon);
	
	for(;startB<=finishB;startB++)
		attach(terms[startB].coef,terms[startB].expon);   
	
	*finishD=avail-1;
}
