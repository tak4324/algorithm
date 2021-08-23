#include <iostream>

using namespace std;


void quicksort(int array[],int start,int end,int n)
{
	
	if(start >=end) // element num  1   
	{
		return ;
	}
	int key=start; 
	int i=start+1;
	int j=end;
	int temp;
		
	while(i<=j) //cross turn 
	{
		while(array[i] >= array[key])
		{
			i++;
		}
		while(array[j]<=array[key] &&j>start)
		{
			j--;
		}
		
		if(i>j)
		{
			temp=array[j];
			array[j]=array[key];
			array[key]=temp;
		}else
		{
			temp=array[j];
			array[j]=array[i];
			array[i]=temp;	
		}
	} 
	
	quicksort(array,start,j-1,n);
	quicksort(array,j+1,end,n);

	
}
int main(void)
{
	int array[10]={4,1,3,2,5,6,7,10,9,8};
	int n=10;
	
	cout<<"array "<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	cout<<"after sort array"<<endl;
	
	quicksort(array,0,n-1,n);
	
	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
