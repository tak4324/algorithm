#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct {
	char stack[SIZE];
	int top;	
}stack_type;


int eval(char ch[]);
void init(stack_type *s);
int isEmpty(stack_type *s);
int isFull(stack_type *s);
void push(stack_type *s, char ch);
char pop(stack_type *s);
char peek(stack_type *s); // s->top 데이터 가져오기  

int main(void)
{
	
	char str[100];
	printf("후기표기식INPUT: ");
	scanf("%s",str);
	
	int result=eval(str);
	
	printf("result=%d\n",result);

	return 0;
}

int eval(char ch[])
{
	stack_type s;
	char c;
	int op1,op2;
	int len=strlen(ch);
	
	int i=0;
	init(&s);
	
	int num;
	for(i=0;i<len;i++)
	{
		c=ch[i];
		
		if(c!='+'&& c != '-' && c!='*' && c!='/')
		{
			 num=c-'0';
			push(&s,num);
		}
		else
		{	
			op2=pop(&s);
			op1=pop(&s);
		
			if(c=='+')
				push(&s,op1+op2);
			else if(c=='-')
				push(&s,op1-op2);
			else if(c=='*')
				push(&s,op1*op2);	
			else if(c=='/')
				push(&s,op1/op2);
			else
			{
				printf("올바른 연산자가 아닙니다.\n");
				exit(1);	
			}		
		}
	}
	return pop(&s);// 마지막 결과값 반환  
}
void init(stack_type *s)
{
	s->top=-1;
}

int isEmpty(stack_type *s)
{	
	if(s->top==-1)
	{
		return 1;
	}
	return 0;
}
int isFull(stack_type *s)
{
	if(s->top==SIZE-1)
	{
		return 1;
	}
	return 0;
}
void push(stack_type *s, char ch)
{
	if(isFull(s))
	{
		printf("Stack is full\n");
		exit(1);
	}
	s->stack[++(s->top)]=ch;
}
char pop(stack_type *s)
{
	if(isEmpty(s))
	{
		printf("Stack is empty \n");
		exit(1);
	}
	return s->stack[(s->top)--];
}
char peek(stack_type *s)
{
	if(isEmpty(s))
	{
		printf("Stack is empty \n");
		return;
	}
	return s->stack[s->top];
}

