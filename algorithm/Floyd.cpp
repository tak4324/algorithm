#include <iostream>

using namespace std;

int number=4;
int INF=1000000;

int a[4][4]={
	{0, 	5, INF, 8},
	{7, 	0,   9,INF},
	{2,	  INF,   0, 4},
	{INF, INF,	 3, 0},
			
}; //basic 

int d[4][4]; // result array;

void floyd()
{
	for(int i=0;i<number;i++)
	{
		for(int j=0;j<number;j++)
		{
			d[i][j]=a[i][j]; //basic setting 
		}
	}
	
	for(int k=0;k<number;k++)
	{
		for(int i=0;i<number;i++)
		{
			for(int j=0;j<number;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
}
int main(void)
{
	floyd();
	
	for(int i=0;i<number;i++)
		{
			for(int j=0;j<number;j++)
			{
				cout<<d[i][j]<<" ";
			}
			cout<<endl;
		}
	return 0;
}
