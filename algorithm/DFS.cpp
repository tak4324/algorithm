#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int number=7;

bool visited[8]={false,};
vector<int> a[8];

void dfs(int start)
{
	if(visited[start])// stop point
		return; 
	
	visited[start]=true;
	cout<<start<<" ";
	
	for(int i=0;i<a[start].size();i++)
	{
		int y=a[start][i];
		dfs(y);
	}
}

void dfs1(int start)
{
	stack<int> s;
	s.push(start);
	visited[start]=true;
 	cout<<start<<" ";
 	while(!s.empty())
	{	
		int x=s.top();
		s.pop();
		for(int i=0;i<a[x].size();i++)
		{
			int y=a[x][i];
			
			if(visited[y]==false)
			{
				visited[y]=true;
				
				cout<< y<<" ";
				s.push(x);
				s.push(y);
				
			}
		}	
	} 	
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1); 
	
	a[1].push_back(3); 
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[6].push_back(7);
	a[7].push_back(6);
	dfs1(1);
	dfs(1);
	//1-2-3-6-7-4-5
	return 0;
}
