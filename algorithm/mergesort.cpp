#include <iostream>

using namespace std;

int sorted[10];

void merge(int array[],int start,int middle,int end)
{
	int i=start;
	int j=middle+1;
	int k=start;
	
	while(i<=middle && j<=end)
	{
		if(array[i]<=array[j])
		{
			sorted[k]=array[i];
			i++;
		}else
		{
			sorted[k]=array[j];
			j++;
		}
		k++;
	}
	

	if(i>middle)
	{
		for(int t=j;t<=end;t++)
		{
			sorted[k]=array[t];
			k++;
		}	
	}else
	{
		for(int t=i;t<=middle;t++)
		{
			sorted[k]=array[t];
			k++;
		}	
	}
	for(int t=start;t<=end;t++)
	{
		array[t]=sorted[t];	
	}	
	
}

void mergesort(int array[],int start,int end)
{
	if(start<end)
	{
		int middle=(start+end)/2;
		mergesort(array,start,middle);
		mergesort(array,middle+1,end);
		merge(array,start,middle,end);
	}
	
}
int main(void)
{
	int array[10]={5,2,3,4,10,8,9,1,7,6};
	int n=10;
	
	cout<<"array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	
	cout<<endl;
	cout<<"After sort array"<<endl;
	
	mergesort(array,0,n-1);
	
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	return 0;
	
}
