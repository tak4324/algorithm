#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createnode(int data)
{
	node *newnode =(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
	
}

int main(void)
{
	node *node1,*node2;

	node1=createnode(10);
	node2=createnode(20);
	
	node1->next=node2;
	
	for(node *temp=node1;temp!=NULL;)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	
	
	return 0;
}
