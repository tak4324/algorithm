#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct CList{
	node *tail;
	node *cur;
	node *before;
	int numofData;
}CList;

typedef struct CList List;

void ListInit(List *plist);
void LInsert(List *plist,int data);
void LInsertFront(List *plist, int data);

int Lfirst(List *plist,int *pdata);
int LNext(List *plist,int *pdata);
int Lremove(List *plist);
int LCount(List *plist);


int main(void)
{
	List list;
	int data, i, num;
	ListInit(&list);
	
	LInsert(&list,3);
	LInsert(&list,4);
	LInsert(&list,5);
	printf("list %d \n",list.tail->data);
	LInsertFront(&list,2);
	LInsertFront(&list,1);
	printf("list %d \n",list.tail->data);
	
	if(Lfirst(&list,&data))
	{
		printf("Lfirst-data=%d\n ",data);
		
		for(i=0;i<LCount(&list)*3-1;i++)
		{
			if(LNext(&list,&data))
			{
				printf("%d ",data);
			}
		}
	}
	printf("\n");
	
	num=LCount(&list);


	if(num!=0)
	{
		Lfirst(&list,&data);
		if(data%2==0)
			Lremove(&list);
		
		for(i=0;i<num-1;i++)
		{
			LNext(&list,&data);
			if(data%2==0)
				Lremove(&list);
		}	
	}
	if(Lfirst(&list,&data))
	{
		printf("%d ",data);
		
		for(i=0;i<LCount(&list)-1;i++)
		{
			if(LNext(&list,&data))
			{
				printf("%d ",data);
			}
		}
	}
	
	return 0;
}

int Lremove(List *plist)
{
	node *rpos=plist->cur;
	int rdata=rpos->data;
	
	if(rpos==plist->tail)//²¿¸® ³ëµå 
	{
		if(plist->tail==plist->tail->next)
		{
			plist->tail=NULL;	
		}else
		{
			plist->tail=plist->before;
		}
	}
	plist->before->next=plist->cur->next;
	plist->cur=plist->before;
	
	free(rpos);
	(plist->numofData)--;
	return rdata;		
}

int LCount(List *plist)
{
	return plist->numofData;
}
int Lfirst(List *plist, int *pdata)
{
	if(plist->tail==NULL)
		return 0;
	
	plist->before=plist->tail;
	plist->cur=plist->tail->next;
	
	*pdata=plist->cur->data;
	 	return 1;	
}
int LNext(List *plist,int *pdata)
{
	if(plist->tail==NULL)
		return 0;
		
	plist->before=plist->cur;
	plist->cur=plist->cur->next;
	
	*pdata=plist->cur->data;	
		
	return 1;
	
}
void ListInit(List *plist)
{
	plist->before=NULL;
	plist->cur=NULL;
	plist->numofData=0;
	plist->tail=NULL;
}

void LInsert(List *plist,int data)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	
	if(plist->tail==NULL)
	{
		plist->tail=newnode;
		newnode->next=newnode;
	}else
	{
		newnode->next=plist->tail->next;
		plist->tail->next=newnode;
	}
	(plist->numofData)++;
	
	
}
void LInsertFront(List *plist, int data)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	
	
	if(plist->tail==NULL)
	{
		plist->tail=newnode;
		newnode->next=newnode;
	}else
	{
		newnode->next=plist->tail->next;
		plist->tail->next=newnode;
		plist->tail=newnode;
	}
	
	(plist->numofData)++;
	
}



