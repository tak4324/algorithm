#include <iostream>

using namespace std;

void insertion_sort(int array[],int n)
{
	int temp;
	int j;
	for(int i=0;i<n;i++)
	{
		j=i;
		while(array[j]>array[j+1])
		{
			temp=array[j];
			array[j]=array[j+1];
			array[j+1]=temp;
			j--;
		}
	}
}
void insertion_sort2(int array[],int n)
{
	int i,j;
	int temp;
	
	for(int i=1;i<n;i++)
	{
		temp=array[i];
		for(j=i-1;j>=0;j--)
		{
			if(array[j]>temp)
			{
				array[j+1]=array[j];
			}else
			{
				break;
			}
		}
		array[j+1]=temp;
	}
}
int main(void)
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
	//insertion_sort(array,n);
	insertion_sort2(array,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
