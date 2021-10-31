#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct {
	char stack[SIZE];
	int top;	
}stack_type;


int prec(char op);
void infix_to_postfix(char ch[]);

void init(stack_type *s);
int isEmpty(stack_type *s);
int isFull(stack_type *s);
void push(stack_type *s, char ch);
char pop(stack_type *s);
char peek(stack_type *s);


int main(void)
{
	char str[100];
	printf("중위표기식을 입력하세요 ");
	scanf("%s",str);
	infix_to_postfix(str);
	 
	return 0;
}

void infix_to_postfix(char ch[])
{
	
	int i;
	char c,top_op;
	int len=strlen(ch);
	
	stack_type s;
	init(&s);
	
	for(i=0;i<len;i++)
	{
		c=ch[i];
		if(c=='+'|| c == '-' || c=='*' || c=='/')
		{
			while(!isEmpty(&s)&& prec(c)<=prec(peek(&s)))
			{
				printf("%c",pop(&s));
			}
			push(&s,c);
		}
		else if(c=='(')
		{	
			push(&s,c);
		}else if(c==')')
		{
			top_op=pop(&s);
			
			while(top_op!='(')
			{
				printf("%c",top_op);
				top_op=pop(&s);
			}
		}
		else
		{
			printf("%c",c);
		}
	}
	while(!isEmpty(&s))
	{
		printf("%c",pop(&s));
	}	
}

int prec(char op)
{
	switch(op)
	{
		case'(':
			return 0;
		case ')':
			return 0;
		case '+': 
		    return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
	}
	return -1;
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
