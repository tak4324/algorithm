#include <iostream>

using namespace std;

void bubble(int array[],int n)
{
	int temp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

int main()
{
	int array[10]={4,2,3,6,5,1,7,9,10,8};
	int n=10;
	
	cout<<"array "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	cout<<" after sort array "<<endl;
	bubble(array,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
