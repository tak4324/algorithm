#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_COL 50 


typedef struct term{
	int row;
	int col;
	int value;
}term;

void transpose(term a[],term b[])
{
	int n,i,j,currentb;
	
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=a[0].value;
	/
	if(a[0].value>0)
	{

		currentb=1;
		for(i=0;i<a[0].col;i++)
		{
			for(j=1;j<=a[0].value;j++)
			{
				if(a[j].col==i)
				{
					b[currentb].row=a[j].col;
					b[currentb].col=a[j].row;
					b[currentb].value=a[j].value;
					currentb++; 
				}
			}
		}
	}
}

void fast_transpose(term a[],term b[])
{
	int rowTerms[MAX_COL],startingPose[MAX_COL];//rowterms : 행 원소 수  
	int i,j;
	int numCols=a[0].col, numterms=a[0].value;
	
	b[0].row=numCols;
	b[0].col=a[0].row;
	
	if(numterms>0)
	{
	
		for(i=0;i<numCols;i++)
		{
			rowTerms[i]=0;
		}
		for(i=1;i<=numterms;i++)
		{
			rowTerms[a[i].col]++;
		}
		startingPose[0]=1;
		
		for(i=1;i<numCols;i++)
		{
			startingPose[i]=startingPose[i-1]+rowTerms[i-1];//시작인덱스 넣기 
		}
		
		//교환
		for(i=1;i<=numterms;i++)
		{
			j=startingPose[a[i].col]++;
			b[j].row=a[i].col; 
			b[j].col=a[i].row;
			b[j].value=a[i].value;
		} 
	}
}
int main(void)
{
	term a[MAX_SIZE],b[MAX_SIZE];
	int i;
	scanf("%d %d %d",&a[0].row,&a[0].col,&a[0].value);
	
	for(i=1;i<=a[0].value;i++)
	{
		scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
	}
	printf("\n\n");
	transpose(a,b);
	
	for(i=1;i<=b[0].value;i++)
	{
		printf("%d %d %d\n",b[i].row,b[i].col,b[i].value);
	}
	return 0;
}


