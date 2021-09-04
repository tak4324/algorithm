#include <iostream>
#include <vector>
#include <queue>

/*
	this is topologySort
	cycle x  
	using stack (Dfs) ,queue 
	this topology sort used to queue data structure

*/

using namespace std;

int MAX=10;
int result[10];
int n=7;
int inDegree[10];

vector<int> a[10];

void topologySort()
{
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		if(inDegree[i]==0)
		{
			q.push(i);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(q.empty())
		{
			cout<<"cycle !! "<<endl;
			return;
		}
		int x=q.front();
		q.pop();
		result[i]=x;
		for(int i=0;i<a[x].size();i++)
		{
			int y=a[x][i];
			if(--inDegree[y]==0)
			{
				q.push(y);
			}	
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	
	
}

int main()
{
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	
	a[2].push_back(3);
	inDegree[3]++;
	
	a[3].push_back(4);
	inDegree[4]++;
	
	a[4].push_back(6);
	inDegree[6]++;
	
	a[5].push_back(6);
	inDegree[6]++;
	
	a[6].push_back(7);
	inDegree[7]++;
	
	topologySort();
	
	return 0;
}
