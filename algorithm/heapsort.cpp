#include <iostream>

using namespace std;

void heap(int array[],int n)
{
	int root,child;
	for(int i=1;i<n;i++)
	{
		child=i;
		
		while(child!=0)
		{
			root=(child-1)/2;
			if(array[root]<array[child])
			{
				int temp=array[root];
				array[root]=array[child];
				array[child]=temp;
			}	
			child=root;			
		}
		
	}
}

void heapsort(int array[],int n)
{
	int root,child;
	
	for(int i=n-1;i>=0;i--)
	{
		int temp=array[0];
		array[0]=array[i];
		array[i]=temp;
		
		child=1;
		root=0;
		while(child<i)
		{
			child=2*root+1;
			if(array[child]<array[child+1]&& child<i-1)
			{
				child++;
				
			}
			if(array[root]<array[child]&&child<i)
			{
				temp=array[root];
				array[root]=array[child];
				array[child]=temp;
			}
			root=child;
		}
			
	}
}

int main(void)
{
	int array[9]={7,6,5,8,3,5,9,1,6};
	int n=9;
	
	cout<<"array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	heap(array,n);
	
	cout<<"after heapfipy array"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	heapsort(array,n);
	cout<<"after sort array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}
