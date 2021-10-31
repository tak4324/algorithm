#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 //stack size 
#define TRUE 1 
#define FALSE 0
#define ROW 10
#define COL 10

 
typedef struct{
	int x;
	int y;
	
}offsets;

offsets move[8]=
{	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1}
};
//合率0 合悼率 1 悼率 2 悼巢率 3 巢率 4 巢辑率 5 辑率 6 合辑率 7 
typedef struct{
	int row;
	int col;
	int dir;
}element;
 
element stack[SIZE];
int top=-1;
int maze[ROW][COL];
int mark[ROW+2][COL+2];

void path(void);
void push(element position);
element pop(void);

int main(void)
{
	int i,j;
	srand((unsigned)time(NULL));
	
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(i==1&&j==1)
				maze[i][j]=0;
			else if(i==0 || j==0 ||(i==ROW-1)||(j==COL-1))
				maze[i][j]=1;
			else
				maze[i][j]=rand()%2;
		}
	}
	printf("--------------------maze-----------\n");
	printf("\n\n");
	
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%2d ",maze[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	printf("-------------------------------------\n");
	path();

	return 0;
}
void push(element position)
{

	++top;
	stack[top].row=position.row;
	stack[top].col=position.col;
	stack[top].dir=position.dir;
}
element pop(void)
{
	element result;
	if(top<0)
	{
		printf("stack is Empty\n");
		exit(1);
	}
	result=stack[top];
	top--;
	return result;
}

void path(void)
{
	int i;
	int row,col,next_row,next_col,dir;
	int found=FALSE;
	element position;
	mark[1][1]=1;
	top=0;
	stack[0].row=1;
	stack[0].col=1;
	stack[0].dir=0;
	
	while(top>-1 && !found) //  
	{
		position=pop();
		row=position.row;
		col=position.col;
		dir=position.dir;
		
		while(dir<8 &&!found) //search 
		{
			next_row=row+move[dir].x;
			next_col=col+move[dir].y;
			
			if(next_row==ROW-1 && next_col==COL-1)
			{
				found=TRUE;
			}else if(!maze[next_row][next_col]&&!mark[next_row][next_col])
			{
				mark[next_row][next_col]=1;
				position.row=row;
				position.col=col;
				position.dir=++dir;
				push(position);
				row=next_row;
				col=next_col;
				dir=0;
			}else
			{
				++dir;
			}		
		}
	}
	if(found)
	{
		printf("path is: \n");
		printf("row col\n");
		for(i=0;i<=top;i++)
		{
			printf("%2d %5d\n",stack[i].row,stack[i].col);
		}
		printf("%2d %5d\n",row,col);
		printf("%2d %5d\n",ROW-1,COL-1);
	}else
	{
		printf("MAZE does not have a path\n");
	}
}
