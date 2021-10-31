#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int isEmpty();
int isFull();
void enqueue(int data);
int dequeue();
void show();

int rear=0;
int front=0;
int Cqueue[MAX];

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	
	return 0;
}
int isEmpty()
{
	if(front==rear)
	{
		return 1;
	}
	return 0;
}
int isFull()
{
	if(front==((rear+1)%MAX))
	{
		
		return 1;
	}
	return 0;
}
void enqueue(int data)
{
	if(isFull())
	{
		printf("원형 큐가 꽉 찼습니다.\n");
		exit(1);
	}
	rear=(rear+1)%MAX;
	Cqueue[rear]=data;
}

int dequeue()
{
	if(isEmpty())
	{
		printf("원형 큐가 비었습니다.\n");
		exit(1);
	}
	front=(front+1)%MAX;
	return Cqueue[front];
}

