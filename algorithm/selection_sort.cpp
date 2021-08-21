#include <iostream>

using namespace std;

int array[10]={1,3,5,7,9,10,2,4,6,8};

void selection_sort(int ary[],int n)
{
	int i,j;
	int temp;
	int min=ary[0];
	int index=0;
	
	for(i=0;i<n;i++)
	{
		min=ary[i];
		for(j=i+1;j<10;j++)
		{
			if(ary[j]<min)
			{
				min=ary[j];
				index=j;
			}
		}
		temp=ary[i];
		ary[i]=ary[index];
		ary[index]=temp;	
	}

}

int main(void)
{
	int n=10;
	
	cout<<"array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	selection_sort(array,n);
	cout<<"after sort array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
