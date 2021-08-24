#include <iostream>
#include <queue>

#define MAX 100

using namespace std;

int queue1[MAX];
int rear=-1;
int front=-1;

void enqueue(int data);
int dequeue();
void print();

int main()
{
	queue<int> q; 
	q.push(7);
	q.push(4);
	q.push(3);
	
	
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	print();
	dequeue();
	cout<<endl;
	
	print();
	
	
	return 0;
}
void enqueue(int data)
{
	if(rear>=MAX)
	{
		cout<<"queue is full"<<endl;
	}else if(rear==-1&&front==-1)
	{
		rear++;
		front++;
		queue1[rear]=data;
	}
	else
	{
		rear++;
		queue1[rear]=data;
	}
	
}
int dequeue()
{
	if(rear==front)
	{
		cout<<"queue is empty"<<endl;
	}else 
	{
		front++;
		queue1[front];
	}
}
void print()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<queue1[i]<<" ";
	}
}
