#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // fill(iterater t, iterater t1,const T& target) 

/*
	Network algorithm
	Edmonds-karp algorithm
	Using BFS 
*/

#define MAX 100
#define INF 10000000
using namespace std;

int n=6,result;
int capacity[MAX][MAX];
int flow[MAX][MAX];
int d[MAX];

vector<int> a[MAX];



void maxflow(int start,int end)
{
	int i=0;
	while(1)
	{
		fill(d,d+MAX,-1); //d array -1 setting
		queue<int> q;
		q.push(start);
		
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<a[x].size();i++)
			{
				int y=a[x][i];
				// not visited 	remain capacity
				if(capacity[x][y] - flow[x][y] > 0  && d[y] == -1)
				{
					q.push(y);
					d[y]=x;//memory path 
					
					if(y==end) // arrive target 
						break;	
				}		
			}
		}
		
		if(d[end]==-1) //after search all path escape   
		{
			break;
		}
		int f =INF;
		for(int i=end;i!=start;i=d[i]) //revesere flow search 
		{
			f=min(f,capacity[d[i]][i]-flow[d[i]][i]);
		}
		for(int i=end;i!=start;i=d[i])
		{
			flow[d[i]][i]+=f;
			flow[i][d[i]]-=f;
		}
		result+=f;
	}	
}

int main(void)
{
	
	a[1].push_back(2);
	a[2].push_back(1);
	capacity[1][2]=12;
	
	a[1].push_back(4);
	a[4].push_back(1);
	capacity[1][4]=11;
	
	a[2].push_back(3);
	a[3].push_back(2);
	capacity[2][3]=6;
	
	a[2].push_back(4);
	a[4].push_back(2);
	capacity[2][4]=3;
	
	a[2].push_back(5);
	a[5].push_back(2);
	capacity[2][5]=5;
	
	a[2].push_back(6);
	a[6].push_back(2);
	capacity[2][6]=9;
	
	a[3].push_back(6);
	a[6].push_back(3);
	capacity[3][6]=8;
	
	a[4].push_back(5);
	a[5].push_back(4);
	capacity[4][5]=9;
	
	a[5].push_back(3);
	a[3].push_back(5);
	capacity[5][3]=3;
	
	a[5].push_back(6);
	a[6].push_back(5);
	capacity[5][6]=4;
	
	maxflow(1,6);
	
	cout<<result<<endl;
	
	
	return 0;
}
