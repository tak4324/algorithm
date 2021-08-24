#include <iostream>
#include <stack>

#define MAX 100 
using namespace std;

int stack1[MAX];
int top=-1;

int pop();
void push(int data);
void print();

//stack push({Tvalue})
//stack pop()
//stack empty()
//stack top()
//stack size() 

int main(void)
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();


	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
	cout<<endl<<"make stack "<<endl;
	
	push(10);
	push(20);
	push(30);
	print();
	cout<<endl;
	
	pop();
	print();
	
	return 0;
}

int pop()
{
	if(top==NULL)
	{
		cout<<"stack is empty"<<endl;
		return -1;
	}
	
	top--;
	return stack1[top];
	
}
void push(int data)
{
	if(top>MAX)
	{
		cout<<"stack is full"<<endl;
		
	}
	else
	{
		top++;
		stack1[top]=data;
		
	}
	
}
void print()
{
	for(int i=0;i<=top;i++)
	{
		cout<<stack1[i]<<endl;
	}
	
}
